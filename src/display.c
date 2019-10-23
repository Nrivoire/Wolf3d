/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 13:08:55 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 13:11:06 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			background(t_env *v)
{
	int			sky;
	int			land;

	sky = -1;
	while (++sky <= HEIGHT / 2)
	{
		land = -1;
		while (++land <= WIDTH)
		{
			SDL_RenderDrawPoint(v->ren, land, sky);
			SDL_SetRenderDrawColor(v->ren, 140, 140, 140, 255);
		}
	}
	sky = HEIGHT / 2;
	while (++sky <= HEIGHT)
	{
		land = -1;
		while (++land <= WIDTH)
		{
			SDL_RenderDrawPoint(v->ren, land, sky);
			SDL_SetRenderDrawColor(v->ren, 179, 179, 179, 255);
		}
	}
}

void			display(t_env *v)
{
	SDL_Event	event;

	while (1)
	{
		background(v);
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				break;
			if (event.type == SDL_KEYDOWN)
				key_event(event, v);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				mouse_button_event(event, v);
			if (event.type == SDL_MOUSEMOTION)
				mouse_motion_event(event, v);
			SDL_SetRelativeMouseMode(v->bool_cursor);
			SDL_WarpMouseInWindow(v->win, WIDTH / 2, HEIGHT / 2);
			render(v);
			SDL_RenderPresent(v->ren);
		}
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
}
