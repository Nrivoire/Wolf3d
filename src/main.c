/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:09:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 19:47:08 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			init(t_env *v)
{
	v->pos.dir.x = 0;
	v->pos.dir.y = -1;
	v->pos.plane.x = -(FIELDOFVIEW / 100);
	v->pos.plane.y = 0;
	v->pos.time = 0;
	v->pos.oldtime = 0;
}

void			background(t_env *v)
{
	int			sky;
	int			land;

	sky = -1;
	while (++sky <= HEIGHT / 2)
	{
		land = -1;
		while (++land <= WIDTH)
		{
			SDL_RenderDrawPoint(v->ren, land, sky);
			SDL_SetRenderDrawColor(v->ren, 135, 206, 235, 255);
		}
	}
	sky = HEIGHT / 2;
	while (++sky <= HEIGHT)
	{
		land = -1;
		while (++land <= WIDTH)
		{
			SDL_RenderDrawPoint(v->ren, land, sky);
			SDL_SetRenderDrawColor(v->ren, 210, 180, 140, 255);
		}
	}
}

int		main(int av, char **ac)
{
	t_env		*v;
	int			fd;
	SDL_Event	event;

	fd = -1;
	if (av != 2 || (fd = open(ac[1], O_RDONLY)) < 0)
		ft_error("usage: ./wolf3d map");
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	init(v);
	v->col = 0;
	v->row = 0;
	v->pos.pos.y = -1;
	v->pos.pos.x = -1;
	make_map(v, fd);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error("Couldn't initialize SDL");
	v->win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	if (v->win == NULL)
		ft_error("Could not create the window");
	v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE);
	if (v->ren == NULL)
		ft_error("Could not create a renderer");
	int		ix;
	int		jx;
	int		iy;
	int		jy;
	jx = 200;
	ix = 10;
	iy = 10;
	jy = 200;
	while (1)
	{
		//const Uint8 *key = SDL_GetKeyboardState(NULL);
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
		background(v);
		//if (key[SDL_SCANCODE_DOWN])
		//	my_sdl_drawline(make_spot(ix, ++iy), make_spot(jx, ++jy), make_rgb(255, 255, 255, 225), v);
		//if (key[SDL_SCANCODE_UP])
		//	my_sdl_drawline(make_spot(ix, --iy), make_spot(jx, --jy), make_rgb(255, 255, 255, 225), v);
		//if (key[SDL_SCANCODE_RIGHT])
		//	my_sdl_drawline(make_spot(++ix, iy), make_spot(++jx, jy), make_rgb(255, 255, 255, 225), v);
		//if (key[SDL_SCANCODE_LEFT])
		//	my_sdl_drawline(make_spot(--ix, iy), make_spot(--jx, jy), make_rgb(255, 255, 255, 225), v);	
		SDL_SetRenderDrawColor(v->ren, 0, 0, 0, 255);
		SDL_RenderPresent(v->ren);
		SDL_RenderClear(v->ren);
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
	return (0);
}
