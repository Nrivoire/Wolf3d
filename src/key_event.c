/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 13:06:17 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 16:39:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				dtoi(double dbl)
{
	int	ret;

	ret = dbl;
	return dbl;
}

void			movement(const Uint8 *keyboard_state, t_env *v)
{
	if (keyboard_state[SDL_SCANCODE_DOWN] || keyboard_state[SDL_SCANCODE_S])
	{
		SDL_RenderClear(v->ren);
		background(v);
		if (!v->map[dtoi(v->pos.pos.x - cos(v->rad[v->pos.angle]) * v->movespeed)][dtoi(v->pos.pos.y)])
			v->pos.pos.x -= cos(v->rad[v->pos.angle]) * v->movespeed;
		if (!v->map[dtoi(v->pos.pos.x)][dtoi(v->pos.pos.y - sin(v->rad[v->pos.angle]) * v->movespeed)])
			v->pos.pos.y -= sin(v->rad[v->pos.angle]) * v->movespeed;
	}
	if (keyboard_state[SDL_SCANCODE_UP] || keyboard_state[SDL_SCANCODE_W])
	{
		SDL_RenderClear(v->ren);
		background(v);
		if (!v->map[dtoi(v->pos.pos.x + cos(v->rad[v->pos.angle]) * v->movespeed)][dtoi(v->pos.pos.y)])
			v->pos.pos.x += cos(v->rad[v->pos.angle]) * v->movespeed;
		if (!v->map[dtoi(v->pos.pos.x)][dtoi(v->pos.pos.y + sin(v->rad[v->pos.angle]) * v->movespeed)])
			v->pos.pos.y += sin(v->rad[v->pos.angle]) * v->movespeed;
	}
	if (keyboard_state[SDL_SCANCODE_RIGHT] || keyboard_state[SDL_SCANCODE_D])
	{
		SDL_RenderClear(v->ren);
		background(v);
		if (!v->map[dtoi(v->pos.pos.x)][dtoi(v->pos.pos.y - cos(v->rad[v->pos.angle]) * v->movespeed)])
			v->pos.pos.y -= cos(v->rad[v->pos.angle]) * v->movespeed;
		if (!v->map[dtoi(v->pos.pos.x + sin(v->rad[v->pos.angle]) * v->movespeed)][dtoi(v->pos.pos.y)])
			v->pos.pos.x += sin(v->rad[v->pos.angle]) * v->movespeed;
	}
	if (keyboard_state[SDL_SCANCODE_LEFT] || keyboard_state[SDL_SCANCODE_A])
	{
		SDL_RenderClear(v->ren);
		background(v);
		if (!v->map[dtoi(v->pos.pos.x)][dtoi(v->pos.pos.y + cos(v->rad[v->pos.angle]) * v->movespeed)])
			v->pos.pos.y += cos(v->rad[v->pos.angle]) * v->movespeed;
		if (!v->map[dtoi(v->pos.pos.x - sin(v->rad[v->pos.angle]) * v->movespeed)][dtoi(v->pos.pos.y)])
			v->pos.pos.x -= sin(v->rad[v->pos.angle]) * v->movespeed;
	}
}

void			key_event(const Uint8 *keyboard_state, t_env *v)
{
	if (keyboard_state[SDL_SCANCODE_LSHIFT])
		v->movespeed = 1.2;
	else
		v->movespeed = 1;
	if (keyboard_state[SDL_SCANCODE_UP] || keyboard_state[SDL_SCANCODE_DOWN] || keyboard_state[SDL_SCANCODE_RIGHT] || keyboard_state[SDL_SCANCODE_LEFT])
		movement(keyboard_state, v);
	else if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_A])
		movement(keyboard_state, v);
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		ft_error(NULL);
}
