/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 13:08:55 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 18:52:57 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		topbackground(t_env *v)
{
	int			y;
	int			x;
	int			color;

	color = 0;
	y = HEIGHT / 2;
	while (--y >= 0)
	{
		x = -1;
		while (++x <= WIDTH)
		{
			SDL_RenderDrawPoint(v->ren, x, y);
			SDL_SetRenderDrawColor(v->ren, color / 10, color / 1.2, color, 255);
		}
		if (y % 2 == 0 && color < 200)
			color++;
	}
}

void			background(t_env *v)
{
	int			y;
	int			x;
	int			color;

	SDL_SetRenderTarget(v->ren, v->back);
	topbackground(v);
	color = 0;
	y = HEIGHT / 2;
	while (++y <= HEIGHT)
	{
		x = -1;
		while (++x <= WIDTH)
		{
			SDL_RenderDrawPoint(v->ren, x, y);
			SDL_SetRenderDrawColor(v->ren, color, color, color, 255);
		}
		if (y % 2 == 0 && color < 200)
			color++;
	}
	SDL_SetRenderTarget(v->ren, NULL);
}

void			close_sdl(t_env *v)
{
	SDL_DestroyTexture(v->back);
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
}

void			set_mouse(t_env *v)
{
	SDL_SetRelativeMouseMode(SDL_ENABLE);
	SDL_WarpMouseInWindow(v->win, WIDTH / 2, HEIGHT / 2);
}

void			display(t_env *v)
{
	SDL_Event	event;
	const Uint8	*keyboard_state;

	set_mouse(v);
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			keyboard_state = SDL_GetKeyboardState(NULL);
			if (event.type == SDL_KEYDOWN)
				key_event(keyboard_state, v);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				mouse_button_event(event, v);
			if (event.type == SDL_MOUSEMOTION)
				mouse_motion_event(event, v);
		}
		if (event.type == SDL_QUIT || key_event(keyboard_state, v))
			break ;
		movement_direction(keyboard_state, v);
		movement_side(keyboard_state, v);
		SDL_RenderCopy(v->ren, v->back, NULL, NULL);
		render(v);
		SDL_RenderPresent(v->ren);
	}
	close_sdl(v);
}
