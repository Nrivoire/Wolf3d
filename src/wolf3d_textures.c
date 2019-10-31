/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_textures.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 19:03:37 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 15:14:39 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/* Fonction remplit les surface de env, avec des images en .bmp en 128x128 */

void	assigntextures(t_env *v)
{
	/* bloc NordSudEstOuest */
	if ((v->sur[0][0] = SDL_LoadBMP("./textures/nord.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[0][1] = SDL_LoadBMP("./textures/sud.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[0][2] = SDL_LoadBMP("./textures/est.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[0][3] = SDL_LoadBMP("./textures/ouest.bmp")) == NULL)
		printf("%s\n", SDL_GetError());

	/* bloc 1 multi */
	if ((v->sur[1][0] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[1][1] = SDL_LoadBMP("./textures/metal.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[1][2] = SDL_LoadBMP("./textures/tprz.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[1][3] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());

	/* bloc 2 all rock */
	if ((v->sur[2][0] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[2][1] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[2][2] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[2][3] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
}
