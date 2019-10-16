/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   my_sdl_drawline.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 13:25:36 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 17:34:24 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_rgb			make_rgb(int r, int g, int b, int a)
{
	t_rgb		content;

	content.r = r;
	content.g = g;
	content.b = b;
	content.a = a;
	return (content);
}

t_ixy			make_spot(int x, int y)
{
	t_ixy		content;

	content.x = x;
	content.y = y;
	return (content);
}

t_bressen		init_bresen(t_ixy m1, t_ixy m2)
{
	t_bressen	b;

	b.dx = ft_absolu(m2.x - m1.x);
	b.dy = ft_absolu(m2.y - m1.y);
	b.sx = (m1.x < m2.x ? 1 : -1);
	b.sy = (m1.y < m2.y ? 1 : -1);
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
	return (b);
}

void			my_sdl_drawline(t_ixy m1, t_ixy m2, t_rgb color, t_env *v)
{
	t_bressen	b;

	if ((m1.x < 0 && m1.y < 0 && m2.y < 0 && m2.x < 0) ||
			(m1.x > WIDTH && m1.y > HEIGHT && m2.y > HEIGHT && m2.x > WIDTH))
		return ;
	b = init_bresen(m1, m2);
	while (1)
	{
		SDL_RenderDrawPoint(v->ren, m1.x, m1.y);
		SDL_SetRenderDrawColor(v->ren, color.r, color.g, color.b, color.a);
		if (m1.x == m2.x && m1.y == m2.y)
			break ;
		b.e2 = b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			m1.x += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			m1.y += b.sy;
		}
	}
}
