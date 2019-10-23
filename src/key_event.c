/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 13:06:17 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 13:08:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			movement(SDL_Event event, t_env *v)
{
	if (event.key.keysym.sym == SDLK_DOWN)
	{
		SDL_RenderClear(v->ren);
		background(v);
		v->pos.pos.x -= cos(v->pos.angle);
		v->pos.pos.y -= sin(v->pos.angle);
	}
	if (event.key.keysym.sym == SDLK_UP)
	{
		SDL_RenderClear(v->ren);
		background(v);
		v->pos.pos.x += cos(v->pos.angle);
		v->pos.pos.y += sin(v->pos.angle);
	}
	if (event.key.keysym.sym == SDLK_RIGHT)
	{
		SDL_RenderClear(v->ren);
		background(v);
		v->pos.pos.x += sin(v->pos.angle);
		v->pos.pos.y += cos(v->pos.angle);
	}
	if (event.key.keysym.sym == SDLK_LEFT)
	{
		SDL_RenderClear(v->ren);
		background(v);
		v->pos.pos.x -= sin(v->pos.angle);
		v->pos.pos.y -= cos(v->pos.angle);
	}
}

void			key_event(SDL_Event event, t_env *v)
{
	if (event.key.keysym.sym == SDLK_q)
		v->bool_cursor = v->bool_cursor ? 0 : 1;
	if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_UP \
		|| event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT)
		movement(event, v);
}
