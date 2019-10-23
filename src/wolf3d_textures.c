/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_textures.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 19:03:37 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 19:26:28 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/* Fonction remplit les surface de env, avec des images en .bmp en 128x128 */

void	assigntextures(t_env *v)
{
	if ((v->sur[0] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
	printf("%s\n", SDL_GetError());
	if ((v->sur[1] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
	printf("%s\n", SDL_GetError());
	if ((v->sur[2] = SDL_LoadBMP("./textures/tprz.bmp")) == NULL)
	printf("%s\n", SDL_GetError());
}
