/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_textures.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 19:03:37 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 18:01:20 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		get_texture(t_env *v, t_calc *c, t_tex *tex, float distance)
{
	double	hitx;

	if (!c->side)
	{
		hitx = v->pos.pos.y + distance * c->dir.y;
		tex->ori = (c->dir.x > 0) ? 0 : 1;
	}
	else
	{
		hitx = v->pos.pos.x + distance * c->dir.x;
		tex->ori = (c->dir.y < 0) ? 2 : 3;
	}
	hitx -= floor(hitx);
	tex->x = hitx * 128;
	if (c->side == 0 && c->dir.x > 0)
		tex->x = 128 - tex->x - 1;
	if (c->side && c->dir.y < 0)
		tex->x = 128 - tex->x - 1;
}

void		assigntextures3(t_env *v)
{
	if ((v->sur[7][0] = IMG_Load("./textures/tprz.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[7][1] = IMG_Load("./textures/tprz.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[7][2] = IMG_Load("./textures/tprz.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[7][3] = IMG_Load("./textures/tprz.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[8][0] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[8][1] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[8][2] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[8][3] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[3][0] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[3][1] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[3][2] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[3][3] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
}

void		assigntextures2(t_env *v)
{
	if ((v->sur[4][0] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[4][1] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[4][2] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[4][3] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[5][0] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[5][1] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[5][2] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[5][3] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[6][0] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[6][1] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[6][2] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[6][3] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	assigntextures3(v);
}

void		assigntextures(t_env *v)
{
	if ((v->sur[0][1] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[0][0] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[0][2] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[0][3] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[1][0] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[1][1] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[1][2] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[1][3] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[2][0] = IMG_Load("./textures/est.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[2][1] = IMG_Load("./textures/ouest.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[2][2] = IMG_Load("./textures/sud.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	if ((v->sur[2][3] = IMG_Load("./textures/nord.xpm")) == NULL)
		ft_error((char*)SDL_GetError());
	assigntextures2(v);
}
