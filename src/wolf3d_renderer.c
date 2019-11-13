/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_renderer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 17:18:12 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 20:39:04 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_renderer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:52:44 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 17:02:57 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	gettexturex(t_env *v, t_calc *c, t_tex *tex, double distance)
{
	double	hitx;

	if (!c->side)
	{
		hitx = v->pos.pos.y + distance * c->dir.y;
		tex->ori = (c->dir.x > 0) ? 0 : 1;
	}
	else
	{
		hitx = v->pos.pos.x + distance * c->dir.x;
		tex->ori = (c->dir.y < 0) ? 2 : 3;
	}
	hitx -= floor(hitx);
	tex->x = hitx * TEXWIDTH;
	if (c->side == 0 && c->dir.x > 0)
		tex->x = TEXWIDTH - tex->x - 1;
	if (c->side && c->dir.y < 0)
		tex->x = TEXWIDTH - tex->x - 1;
}

void	draw(t_env *v, t_calc *c, int hit)
{
	double	distance;
	int		wallh;
	t_xy	top;
	t_xy	bot;
	t_tex	tex;

	if (c->side == 0)
		distance = (c->map.x - v->pos.pos.x + (1 - c->step.x) / 2) / c->dir.x;
	else
		distance = (c->map.y - v->pos.pos.y + (1 - c->step.y) / 2) / c->dir.y;
	gettexturex (v, c, &tex, distance);
	distance *= cos(c->ang - v->rad[v->pos.angle]);
	wallh = (int)(HEIGHT / distance);
	top.x = c->x;
	bot.x = c->x;
	tex.dist = (distance < 15) ? 1 - distance/15 : 0.1;
	top.y = HEIGHT / 2 - wallh / 2;
	bot.y = HEIGHT / 2 + wallh / 2;
	tex.hit = hit - 1;
	pthread_mutex_lock(&v->mutex);
	drawtexedline(top, bot, *v, tex);
	pthread_mutex_unlock(&v->mutex);
}

int		dda(t_env *v, t_calc *c)
{
	int		hit;

	if (c->sidedist.x < c->sidedist.y)
	{
		c->map.x += c->step.x;
		c->sidedist.x += c->deltadist.x;
		c->side = 0;
	}
	else
	{
		c->map.y += c->step.y;
		c->sidedist.y += c->deltadist.y;
		c->side = 1;
	}
	hit = v->map[c->map.y][c->map.x];
	if (hit){
		draw(v, c, hit);}
	return (hit);
}

void	raycast(t_env *v, t_calc *c)
{
	c->deltadist.x = fabs(1/ c->dir.x);
	c->deltadist.y = fabs(1 / c->dir.y);
	c->step.x = (c->dir.x < 0) ? -1 : 1;
	c->sidedist.x = (c->dir.x < 0) ? ((v->pos.pos.x - c->map.x) *
			c->deltadist.x):((c->map.x + 1.0 - v->pos.pos.x ) *
				c->deltadist.x);
	c->step.y = (c->dir.y < 0) ? -1 : 1;
	c->sidedist.y = (c->dir.y < 0) ? ((v->pos.pos.y - c->map.y) *
			c->deltadist.y) : ((c->map.y + 1.0 - v->pos.pos.y) *
				c->deltadist.y);
	while (dda(v, c) == 0){}
}

void	renderthread(t_env *v)
{
	int				i;
	int				x;
	t_calc			c;

	pthread_mutex_lock(&v->mutex);
	i = v->thread_index++;
	pthread_mutex_unlock(&v->mutex);
	x = (i * (WIDTH / 8));
	while (x < ((i + 1) * (WIDTH / 8)))
	{
		c.ang = (v->fovmax - v->fovmin) * ((double)x / (double)WIDTH) + v->fovmin;
		c.dir.x = cos(c.ang);
		c.dir.y = sin(c.ang);
		c.map.x = (v->pos.pos.x);
		c.map.y = (v->pos.pos.y);
		c.x = x ;
		raycast(v, &c);
		x++;
	}
	pthread_exit(NULL);
}

void	render(t_env *v)
{
	pthread_t		id[8];
	int				i;

	v->fovmax = 0;
	v->fovmin = 0;
	v->fovmax = v->rad[v->pos.angle - (v->pos.fov / 2) + 360];
	v->fovmin = v->rad[v->pos.angle + (v->pos.fov / 2) + 360];
	v->thread_index = 0;
	i = 0;
	while (i < 8)
	{
		pthread_create(&id[i],
				NULL, (void*)renderthread, (void*)v);
		i++;
	}
	while (i--)
		pthread_join(id[i], NULL);
}
