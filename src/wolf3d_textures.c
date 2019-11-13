/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_textures.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 19:03:37 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 20:50:54 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	assigntextures3(t_env *v)
{
	if ((v->sur[7][0] = SDL_LoadBMP("./textures/ouest.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[7][1] = SDL_LoadBMP("./textures/sud.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[7][2] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[7][3] = SDL_LoadBMP("./textures/tprz.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[8][0] = SDL_LoadBMP("./textures/nord.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[8][1] = SDL_LoadBMP("./textures/ouest.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[8][2] = SDL_LoadBMP("./textures/nord.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[8][3] = SDL_LoadBMP("./textures/ouest.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[3][0] = SDL_LoadBMP("./textures/est.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[3][1] = SDL_LoadBMP("./textures/est.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[3][2] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[3][3] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
//	if ((v->sky = SDL_LoadBMP("./textures/skybox.bmp")) == NULL)
//		printf("%s\n", SDL_GetError());
}

void	assigntextures2(t_env *v)
{
	if ((v->sur[4][0] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[4][1] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[4][2] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[4][3] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[5][0] = SDL_LoadBMP("./textures/metal.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[5][1] = SDL_LoadBMP("./textures/metal.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[5][2] = SDL_LoadBMP("./textures/metal.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[5][3] = SDL_LoadBMP("./textures/metal.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[6][0] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[6][1] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[6][2] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[6][3] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	assigntextures3(v);
}
void	assigntextures(t_env *v)
{
	if ((v->sur[0][0] = SDL_LoadBMP("./textures/nord.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[0][1] = SDL_LoadBMP("./textures/sud.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[0][2] = SDL_LoadBMP("./textures/est.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[0][3] = SDL_LoadBMP("./textures/ouest.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[1][0] = SDL_LoadBMP("./textures/cuivre.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[1][1] = SDL_LoadBMP("./textures/metal.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[1][2] = SDL_LoadBMP("./textures/tprz.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[1][3] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[2][0] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[2][1] = SDL_LoadBMP("./textures/greyrock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[2][2] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	if ((v->sur[2][3] = SDL_LoadBMP("./textures/rock.bmp")) == NULL)
		printf("%s\n", SDL_GetError());
	assigntextures2(v);
}
