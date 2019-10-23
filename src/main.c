/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:09:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 13:53:42 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			make_rad(t_env *v)
{
	int			i;

	i = -1;
	while (++i <= 360)
		v->rad[i] = i * (M_PI / 180);
}

void			init(t_env *v)
{
	v->pos.fov = FIELDOFVIEW;
	v->pos.angle = 90;
	v->pos.time = 0;
	v->pos.oldtime = 0;
	make_rad(v);
	assigntextures(v);
	v->col = 0;
	v->row = 0;
	v->pos.pos.y = -1;
	v->pos.pos.x = -1;
	v->rot_speed = 0.2;
	v->bool_cursor = 1;
	v->bool_cam = 1;
	v->inc = -1;
}

int				main(int av, char **ac)
{
	t_env		*v;
	int			fd;

	fd = -1;
	if (av != 2 || (fd = open(ac[1], O_RDONLY)) < 0)
		ft_error("usage: ./wolf3d map");
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	init(v);
	v->lst = wolf3d_parsing(v, fd);
	map(v);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error("Couldn't initialize SDL");
	v->win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	if (v->win == NULL)
		ft_error("Could not create the window");
	v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE);
	if (v->ren == NULL)
		ft_error("Could not create a renderer");
	display(v);
	return (0);
}
