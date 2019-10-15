/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_renderer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:52:44 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 18:57:24 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw(t_env *v, t_calc *c, int hit, int side)
{
	double	distance;

}

int		dda(t_env *v, t_calc *c)
{
	int		hit;
	int		side;

	if (c->sidedist.x < c->sidedist.y)
	{
		c->sidedist.x += c->deltadist.x;
		c->map.x += c->step.x;
		side = 0;
	}
	else
	{
		c->sidedist.y += c->deltadist.y;
		c->map.y += c->step.y;
		side = 1;
	}
	hit = v->map[c->map.x][c->map.y];
	if (hit)
		draw(v, c, hit, side);
	return (hit);
}

void	raycast(t_env *v, t_calc *c)
{
	c->deltadist.x = fabs(1 / c->raydir.x);
	c->deltadist.y = fabs(1 / c->raydir.y);
	if (c->raydir.x < 0)
	{
		c->step.x = -1;
		c->sidedist.x = (v->pos->dir.x - c->map.x) * c->deltadist.x;
	}
	else
	{
		c->step.x = 1;
		c->sidedist.x = (c->map.x + 1.0 - v->pos->dir.x) * c->deltadist.x;
	}
	if (c->raydir.y < 0)
	{
		c->step.y = -1;
		c->sidedist.y = (v->pos->dir.y - c->map.y) * c->deltadist.y;
	}
	else
	{
		c->step.y = 1;
		c->sidedist.y = (c->map.y + 1.0 - v->pos->dir.y) * c->deltadist.y;
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
		c.raydir.x = v->pos->dir.x + v->pos->plane.x * camera;
		c.raydir.y = v->pos->dir.y + v->pos->plane.y * camera;
		c.map.x = fabs(v->pos->pos.x);
		c.map.y = fabs(v->pos->pos.y);
		raycast(v, &c);
		i++;
	}
}
