/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_renderer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:52:44 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 16:48:36 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	gettexturex(t_env *v, t_calc *c, t_tex *tex, double distance)
{
	//		printf("TEXXIN"),fflush(stdout);
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
	//		printf("TEXXOUT"),fflush(stdout);
}

void	draw(t_env *v, t_calc *c, int hit)
{
	//		printf("I AM IN"),fflush(stdout);
	double	distance;
	int		wallh;
	t_xy	top;
	t_xy	bot;
	t_tex	tex;

		if (c->side == 0) distance = (c->map.x - v->pos.pos.x + (1 - c->step.x) / 2) / c->dir.x;
		else distance = (c->map.y - v->pos.pos.y + (1 - c->step.y) / 2) / c->dir.y;
	/*distance = (sqrt(c->sidedist.x * c->sidedist.x + c->sidedist.y
				* c->sidedist.y)) * cos(v->rad[v->pos.angle] - c->ang);*/
	wallh = (int)(HEIGHT / distance);
	top.x = c->x;
	bot.x = c->x;
	top.y = HEIGHT / 2 - wallh / 2;
	bot.y = HEIGHT / 2 + wallh / 2;
	gettexturex (v, c, &tex, distance);
	tex.hit = hit;
	drawtexedline(top, bot, v, tex);
	//		printf("so i shouldve drawn wall %d at x%f and from y %f->%f idk\n", tex.hit, top.x, top.y, bot.y),fflush(stdout);
}

int		dda(t_env *v, t_calc *c)
{
	int		hit;

	if (fabs(c->sidedist.x) < fabs(c->sidedist.y))
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
	//	if (c->x == WIDTH/2)
	//		printf("dx %f, dy %f, sx %f, sy %f\n", c->deltadist.x, c->deltadist.y, c->sidedist.x, c->sidedist.y);
	if (hit)
		draw(v, c, hit);
	return (hit);
}

void	raycast(t_env *v, t_calc *c)
{
	if (c->dir.x < 0)
	{
		c->step.x = -1;
		c->deltadist.y = -tan(c->ang);
		c->sidedist.y = /*v->pos.pos.y +*/ (((double)c->map.x - v->pos.pos.x) * tan(c->ang));
		if (c->x == WIDTH/2)
			printf("Xneg -");
	}
	else
	{
		c->step.x = 1;
		c->sidedist.y =/* v->pos.pos.y +*/ (((double)c->map.x - v->pos.pos.x) * -tan(c->ang));
		c->deltadist.y = tan(c->ang);
		if (c->x == WIDTH/2)
			printf("Xpos -");
	}
	if (c->dir.y < 0)
	{
		c->step.y = -1;
		c->sidedist.x =/* v->pos.pos.x +*/ (((double)c->map.y - v->pos.pos.y) / tan(c->ang));
		c->deltadist.x = -1/tan(c->ang);
		if (c->x == WIDTH/2)
			printf("Yneg\n");
	}
	else
	{
		c->step.y = 1;
		c->sidedist.x =/* v->pos.pos.x +*/ (((double)c->map.y - v->pos.pos.y) / -tan(c->ang));
		c->deltadist.x = 1/tan(c->ang);
		if (c->x == WIDTH/2)
			printf("Ypos\n");
	}
	if (c->x == WIDTH/2)
		printf("dx %f, dy %f, sx %f, sy %f ang = %f\n", c->deltadist.x, c->deltadist.y, c->sidedist.x, c->sidedist.y, c->ang * (180/M_PI));
	while (dda(v, c) == 0){}
}

void	render(t_env *v)
{
	int				x;
	t_calc			c;
	double			fovmin;
	double			fovmax;

	fovmin = v->rad[v->pos.angle - (v->pos.fov / 2)];
	fovmax = v->rad[v->pos.angle + (v->pos.fov / 2)];
	x = 0;
	while (x < WIDTH)
	{
		c.ang = (fovmax - fovmin) * ((double)x / (double)WIDTH) + fovmin;
		c.dir.x = cos(c.ang);
		c.dir.y = sin(c.ang);
	if (c.x == WIDTH/2)
		printf("Angle min %f, Angle max, %f, angle = %f\n", fovmin * (180/M_PI), fovmax* (180/M_PI), c.ang * (180/M_PI)),fflush(stdout);
		c.map.x = (v->pos.pos.x);
		c.map.y = (v->pos.pos.y);
		c.x = x;
		raycast(v, &c);
		x++;
	}
}
