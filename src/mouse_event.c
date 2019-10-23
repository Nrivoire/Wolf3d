/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:29:22 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 13:06:35 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			mouse_button_event(SDL_Event event, t_env *v)
{
	if (event.button.button == SDL_BUTTON_LEFT)
		v->bool_cam = v->bool_cam ? 0 : 1;
}

void			mouse_motion_event(SDL_Event event, t_env *v)
{
	if (v->bool_cam == 1)
	{
		if (event.motion.xrel < 0)
			v->pos.angle -= event.motion.xrel * v->rot_speed;
		else if (event.motion.xrel > 0)
			v->pos.angle += event.motion.xrel * v->rot_speed;
		if (v->pos.angle > 360)
			v->pos.angle = 0;
		if (v->pos.angle < 0)
			v->pos.angle = 360;
	}
}
