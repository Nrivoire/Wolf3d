/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 13:06:17 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 18:49:04 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		dtoi(float dbl)
{
	int	ret;

	ret = dbl;
	return (dbl);
}

void			movement_direction(const Uint8 *keyboard_state, t_env *v)
{
	float		co;
	float		si;

	co = cos(v->rad[v->pos.angle]);
	si = sin(v->rad[v->pos.angle]);
	if (keyboard_state[SDL_SCANCODE_DOWN] || keyboard_state[SDL_SCANCODE_S])
	{
		if (!v->map[dtoi(v->pos.pos.y)][dtoi(v->pos.pos.x - co * v->m_speed)])
			v->pos.pos.x -= co * v->m_speed;
		if (!v->map[dtoi(v->pos.pos.y - si * v->m_speed)][dtoi(v->pos.pos.x)])
			v->pos.pos.y -= si * v->m_speed;
	}
	if (keyboard_state[SDL_SCANCODE_UP] || keyboard_state[SDL_SCANCODE_W])
	{
		if (!v->map[dtoi(v->pos.pos.y)][dtoi(v->pos.pos.x + co * v->m_speed)])
			v->pos.pos.x += co * v->m_speed;
		if (!v->map[dtoi(v->pos.pos.y + si * v->m_speed)][dtoi(v->pos.pos.x)])
			v->pos.pos.y += si * v->m_speed;
	}
}

void			movement_side(const Uint8 *keyboard_state, t_env *v)
{
	float		co;
	float		si;

	co = cos(v->rad[v->pos.angle]);
	si = sin(v->rad[v->pos.angle]);
	if (keyboard_state[SDL_SCANCODE_RIGHT] || keyboard_state[SDL_SCANCODE_D])
	{
		if (!v->map[dtoi(v->pos.pos.y - co * v->m_speed)][dtoi(v->pos.pos.x)])
			v->pos.pos.y -= co * v->m_speed;
		if (!v->map[dtoi(v->pos.pos.y)][dtoi(v->pos.pos.x + si * v->m_speed)])
			v->pos.pos.x += si * v->m_speed;
	}
	if (keyboard_state[SDL_SCANCODE_LEFT] || keyboard_state[SDL_SCANCODE_A])
	{
		if (!v->map[dtoi(v->pos.pos.y + co * v->m_speed)][dtoi(v->pos.pos.x)])
			v->pos.pos.y += co * v->m_speed;
		if (!v->map[dtoi(v->pos.pos.y)][dtoi(v->pos.pos.x - si * v->m_speed)])
			v->pos.pos.x -= si * v->m_speed;
	}
}

int				key_event(const Uint8 *keyboard_state, t_env *v)
{
	if (keyboard_state[SDL_SCANCODE_LSHIFT])
		v->m_speed = fabs(MOVESPEED) * 2;
	else
		v->m_speed = fabs(MOVESPEED);
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	return (0);
}
