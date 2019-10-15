/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:09:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:39:58 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int     		main(int av, char **ac)
{
    t_env		*v;
	int			fd;
	SDL_Event	event;

	fd = -1;
	if (av != 2 || (fd = open(ac[1], O_RDONLY)) < 0)
		ft_error("usage: ./wolf3d map");
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	v->col = 0;
	v->row = 0;
	make_map(v, fd);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error("Couldn't initialize SDL");
	v->win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    if (v->win == NULL)
		ft_error("Could not create the window");
	v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE);
	if (v->ren == NULL)
		ft_error("Could not create a renderer");
	v->sur = SDL_CreateRGBSurface(0, 100, 100, 32, 0, 0, 0, 0);
	if (v->sur == NULL)
		ft_error("Could not create a surface");
	while (1)
	{
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
		my_sdl_drawline(make_spot(10, 10), make_spot(550, 550), make_rgb(255, 255, 255, 225), v);
		SDL_RenderPresent(v->ren);
	}
	SDL_FreeSurface(v->sur);
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
	return (0);
}
