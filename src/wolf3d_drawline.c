/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_drawline.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 17:50:39 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 19:15:35 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

Uint32 GetPixel(SDL_Surface* surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	/*  p est l'addresse du pixel que l'on veut récupérer */
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp)
	{
		case 1:
			return *p;

		case 2:
			return *(Uint16 *)p;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;

		case 4:
			return *(Uint32 *)p;

		default:
			return 0;  /* Ne devrait pas arriver, mais supprime les avertissements du compilateur */
	}
}

void		drawtexedline(t_xy src, t_xy dst, t_env *v, t_tex tex)
{
	SDL_Color	col;
	double		i;

	i = 0.0;
	while (src.y + i < dst.y)
	{
		if (src.x >= 0 && src.x < WIDTH && src.y + i >= 0 &&
				src.y + i < HEIGHT)
		{
			tex.y = ((src.y + i - src.y) / (dst.y - src.y) * TEXWIDTH);
//			printf("1"),fflush(stdout);
			SDL_GetRGBA(GetPixel(v->sur[tex.hit - 1], tex.x, tex.y),
					v->sur[tex.hit - 1]->format, &col.r, &col.g, &col.b, &col.a);
//			printf("3"),fflush(stdout);
			SDL_SetRenderDrawColor(v->ren, col.r, col.g, col.b, col.a);
//			printf("3"),fflush(stdout);
			SDL_RenderDrawPoint(v->ren, src.x, src.y + i);
		}
		i++;
	}
}
/*
   static void	firstcase(t_dxy *src, t_env *v)
   {
   int	i;
   int	xinc;
   int	yinc;
   int	cumul;

   xinc = (param->dx > 0) ? 1 : -1;
   yinc = (param->dy > 0) ? 1 : -1;
   param->dx = fabs(param->dx);
   param->dy = fabs(param->dy);
   cumul = param->dx / 2;
   i = 1;
   while (i <= param->dx)
   {
   src->x += xinc;
   cumul += param->dy;
   if (cumul >= param->dx)
   {
   cumul -= param->dx;
   src->y += yinc;
   }
   if (src->x >= 0 && src->x < WINL && src->y >= 0 && src->y < WINH)
   SDL_RenderDrawPoint(param->ren, src->x, src->y);
   i++;
   }
   }

   static void	secondcase(t_dpos *src, t_param *param)
   {
   int	i;
   int	xinc;
   int	yinc;
   int	cumul;

   xinc = (param->dx > 0) ? 1 : -1;
   yinc = (param->dy > 0) ? 1 : -1;
   param->dx = ft_abs(param->dx);
   param->dy = ft_abs(param->dy);
   cumul = param->dy / 2;
   i = 1;
   while (i <= param->dy)
   {
   src->y += yinc;
   cumul += param->dx;
   if (cumul >= param->dy)
   {
   cumul -= param->dy;
   src->x += xinc;
   }
   if (src->x >= 0 && src->x < WINL && src->y >= 0 && src->y < WINH)
   SDL_RenderDrawPoint(param->ren, src->x, src->y);
   i++;
   }
   }
   *//*
		void		drawline(t_xy *src, t_xy *dst, t_env *v)
		{
		t_xy	ssrc;
		t_xy	d;
		ssrc.x = src->x;
		ssrc.y = src->y;
//	printf("Line (%f,%f);(%f,%f)\n", src->x, src->y, dst->x, dst->y),fflush(stdout);
d.x = dst->x - src->x;
d.y = dst->y - src->y;
//	(dst->z > src->z) ? select_color(param, dst) : select_color(param, src);
if (src->x >= 0 && src->x < WIDTH && src->y >= 0 && src->y < HEIGHT)
SDL_RenderDrawPoint(v->ren, src->x, src->y);
(fabs(d.x) > fabs(d.y)) ? firstcase(src, v, d) :
secondcase(src, v, d);
src->x = ssrc.x;
src->y = ssrc.y;
}*/
