/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_renderer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 17:18:12 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 18:06:20 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		draw(t_env *v, t_calc *c, int hit)
{
	float		distance;
	int			wallh;
	t_xy		top;
	t_xy		bot;
	t_tex		tex;

	if (c->side == 0)
		distance = (c->map.x - v->pos.pos.x + (1 - c->step.x) / 2) / c->dir.x;
	else
		distance = (c->map.y - v->pos.pos.y + (1 - c->step.y) / 2) / c->dir.y;
	get_texture(v, c, &tex, distance);
	if (v->pos.fov < 180)
		distance *= cos(c->ang - v->rad[v->pos.angle]);
	wallh = (int)(HEIGHT / distance);
	if (wallh > HEIGHT * 500)
		wallh = HEIGHT * 500;
	top.x = c->x;
	bot.x = c->x;
	tex.dist = (distance < 15) ? 1 - distance / 15 : 0;
	top.y = HEIGHT / 2 - wallh / 2;
	bot.y = HEIGHT / 2 + wallh / 2;
	tex.hit = hit - 1;
	pthread_mutex_lock(&v->mutex);
	drawtexedline(top, bot, *v, tex);
	pthread_mutex_unlock(&v->mutex);
}

static int		dda(t_env *v, t_calc *c)
{
	int			hit;

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
	if (hit)
		draw(v, c, hit);
	return (hit);
}

static void		raycast(t_env *v, t_calc *c)
{
	c->deltadist.x = fabs(1 / c->dir.x);
	c->deltadist.y = fabs(1 / c->dir.y);
	c->step.x = (c->dir.x < 0) ? -1 : 1;
	c->sidedist.x = (c->dir.x < 0) ? ((v->pos.pos.x - c->map.x) *
			c->deltadist.x) : ((c->map.x + 1.0 - v->pos.pos.x) *
				c->deltadist.x);
	c->step.y = (c->dir.y < 0) ? -1 : 1;
	c->sidedist.y = (c->dir.y < 0) ? ((v->pos.pos.y - c->map.y) *
			c->deltadist.y) : ((c->map.y + 1.0 - v->pos.pos.y) *
				c->deltadist.y);
	while (dda(v, c) == 0)
	{
	}
}

static void		renderthread(t_env *v)
{
	int			i;
	int			x;
	t_calc		c;

	pthread_mutex_lock(&v->mutex);
	i = v->thread_index++;
	pthread_mutex_unlock(&v->mutex);
	x = (i * (WIDTH / 8));
	while (x < ((i + 1) * (WIDTH / 8)))
	{
		c.ang = (v->fovmax - v->fovmin) * ((float)x /
				(float)WIDTH) + v->fovmin;
		c.dir.x = cos(c.ang);
		c.dir.y = sin(c.ang);
		c.map.x = (v->pos.pos.x);
		c.map.y = (v->pos.pos.y);
		c.x = x;
		raycast(v, &c);
		x++;
	}
	pthread_exit(NULL);
}

void			render(t_env *v)
{
	pthread_t	id[8];
	int			i;

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
