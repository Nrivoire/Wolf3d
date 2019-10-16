/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_renderer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:52:44 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 19:51:49 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	gettexturex(t_env *v, t_calc *c, t_tex *tex, double distance)
{
	double	hitx;

	if (!c->side)
		hitx = v->pos.pos.y + distance * c->raydir.y;
	else
		hitx = v->pos.pos.x + distance * c->raydir.x;
	hitx -= floor(hitx);
	tex->x = hitx * TEXWIDTH;
	if (c->side == 0 && c->raydir.x > 0)
		tex->x = TEXWIDTH - tex->x - 1;
	if (c->side && c->raydir.y < 0)
		tex->x = TEXWIDTH - tex->x - 1;
}

void	draw(t_env *v, t_calc *c, int hit)
{
	double	distance;
	int		wallh;
	t_xy	top;
	t_xy	bot;
	t_tex	tex;

	distance = (c->side) ? ((c->map.x - v->pos.pos.x + (1 - c->step.x)
				/ 2)/c->raydir.x) : ((c->map.x - v->pos.pos.x + (1 - c->step.x)
					/ 2)/c->raydir.x);
	wallh = (int)(HEIGHT / distance);
	top.x = c->x;
	bot.x = c->x;
	top.x = (wallh > HEIGHT) ? 0 : HEIGHT / 2 - wallh / 2;
	bot.y = (wallh > HEIGHT) ? HEIGHT : HEIGHT / 2 + wallh / 2;
	gettexturex (v, c, &tex, distance);
	tex.hit = hit;
}

int		dda(t_env *v, t_calc *c)
{
	int		hit;

	if (c->sidedist.x < c->sidedist.y)
	{
		c->sidedist.x += c->deltadist.x;
		c->map.x += c->step.x;
		c->side = 0;
	}
	else
	{
		c->sidedist.y += c->deltadist.y;
		c->map.y += c->step.y;
		c->side = 1;
	}
	hit = v->map[c->map.x][c->map.y];
	if (hit)
		draw(v, c, hit);
	return (hit);
}

void	raycast(t_env *v, t_calc *c)
{
	c->deltadist.x = fabs(1 / c->raydir.x);
	c->deltadist.y = fabs(1 / c->raydir.y);
	if (c->raydir.x < 0)
	{
		c->step.x = -1;
		c->sidedist.x = (v->pos.dir.x - c->map.x) * c->deltadist.x;
	}
	else
	{
		c->step.x = 1;
		c->sidedist.x = (c->map.x + 1.0 - v->pos.dir.x) * c->deltadist.x;
	}
	if (c->raydir.y < 0)
	{
		c->step.y = -1;
		c->sidedist.y = (v->pos.dir.y - c->map.y) * c->deltadist.y;
	}
	else
	{
		c->step.y = 1;
		c->sidedist.y = (c->map.y + 1.0 - v->pos.dir.y) * c->deltadist.y;
	}
	while (dda(v, c)){}
}

void	render(t_env *v)
{
	int				i;
	double			camera;
	t_calc			c;

	i = 0;
	while (i < WIDTH)
	{
		camera = 2 * i / WIDTH - 1;
		c.raydir.x = v->pos.dir.x + v->pos.plane.x * camera;
		c.raydir.y = v->pos.dir.y + v->pos.plane.y * camera;
		c.map.x = fabs(v->pos.pos.x);
		c.map.y = fabs(v->pos.pos.y);
		c.x = i;
		raycast(v, &c);
		i++;
	}
}
