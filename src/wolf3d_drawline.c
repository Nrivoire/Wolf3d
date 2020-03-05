/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_drawline.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 17:50:39 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 18:37:12 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static Uint32		get_pixel(SDL_Surface *surface, int x, int y)
{
	int			bpp;
	Uint8		*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16 *)p);
	else if (bpp == 3)
		return (p[0] | p[1] << 8 | p[2] << 16);
	else if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);
}

void				drawtexedline(t_xy src, t_xy dst, t_env v, t_tex tex)
{
	SDL_Color	col;
	float		i;

	i = (src.y < 0) ? -src.y : 0.0;
	while (src.y + i < dst.y && src.y + i < HEIGHT)
	{
		if (src.x >= 0 && src.x < WIDTH && src.y + i >= 0 && src.y + i < HEIGHT)
		{
			tex.y = ((src.y + i - src.y) / (dst.y - src.y) * 128);
			if (tex.y >= 0 && tex.y < HEIGHT)
			{
				SDL_GetRGBA(get_pixel(v.sur[tex.hit][tex.ori], tex.x, tex.y),
						v.sur[tex.hit][tex.ori]->format,
						&col.r, &col.g, &col.b, &col.a);
				if (tex.ori > 1)
					SDL_SetRenderDrawColor(v.ren, col.r * tex.dist,
							col.g * tex.dist, col.b * tex.dist, col.a);
				else
					SDL_SetRenderDrawColor(v.ren, col.r * .7 * tex.dist, col.g
							* .7 * tex.dist, col.b * .7 * tex.dist, col.a);
				SDL_RenderDrawPoint(v.ren, src.x, src.y + i);
			}
		}
		i++;
	}
}
