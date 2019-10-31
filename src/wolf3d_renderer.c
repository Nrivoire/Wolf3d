/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_renderer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:52:44 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 19:48:47 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	gettexturex(t_env *v, t_calc *c, t_tex *tex, double distance)
{
	double	hitx;

	if (!c->side)
		hitx = v->pos.pos.y + distance * c->dir.y;
	else
		hitx = v->pos.pos.x + distance * c->dir.x;
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

		if (c->side == 0) distance = (c->map.x - v->pos.pos.x + (1 - c->step.x) / 2) / c->dir.x;
		else              distance = (c->map.y - v->pos.pos.y + (1 - c->step.y) / 2) / c->dir.y;
	wallh = (int)(HEIGHT / distance);
	top.x = c->x;
	bot.x = c->x;
	top.y = HEIGHT / 2 - wallh / 2;
	bot.y = HEIGHT / 2 + wallh / 2;
	gettexturex (v, c, &tex, distance);
	tex.hit = hit;
	drawtexedline(top, bot, v, tex);
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
	if (c->dir.x < 0)
	{
		c->step.x = -1;
		c->sidedist.x =/* v->pos.pos.x +*/((v->pos.pos.x - c->map.x) * c->deltadist.x);
}
	else
	{
		c->step.x = 1;
		c->sidedist.x =/* v->pos.pos.x +*/((c->map.x + 1.0 - v->pos.pos.x ) * c->deltadist.x);
	}
	if (c->dir.y < 0)
	{
		c->step.y = -1;
		c->sidedist.y =/* v->pos.pos.x +*/((v->pos.pos.y - c->map.y) * c->deltadist.y);
}
	else
	{
		c->step.y = 1;
		c->sidedist.y =/* v->pos.pos.x +*/((c->map.y + 1.0 - v->pos.pos.y) * c->deltadist.y);
	}
	while (dda(v, c) == 0){}
}

void	render(t_env *v)
{
	int				x;
	t_calc			c;
	double			fovmin;
	double			fovmax;

	fovmax = v->rad[v->pos.angle - (v->pos.fov / 2)];
	fovmin = v->rad[v->pos.angle + (v->pos.fov / 2)];
	x = 0;
	while (x < WIDTH)
	{
		c.ang = (fovmax - fovmin) * ((double)x / (double)WIDTH) + fovmin;
		c.dir.x = cos(c.ang);
		c.dir.y = sin(c.ang);
		c.map.x = (v->pos.pos.x);
		c.map.y = (v->pos.pos.y);
		c.x = x;
		raycast(v, &c);
		x++;
	}
}
