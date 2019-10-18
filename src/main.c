/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:09:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 14:32:21 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			raycasting(t_env *v)
{
	int				fov = 60;
	int				win_half = WIDTH / 2;
	int				distance_mid_cam = win_half / tan(v->rad[30]);
	int				distance_edge_cam = win_half / cos(v->rad[60]);

	printf("%d %d %d\n", fov, distance_mid_cam, distance_edge_cam);
}

void			make_rad(t_env *v)
{
	int			i;

	i = -1;
	while (++i <= 360)
		v->rad[i] = i * (M_PI / 180);
}

void			init(t_env *v)
{
	make_rad(v);
	v->col = 0;
	v->row = 0;
	v->pos.pos.y = -1;
	v->pos.pos.x = -1;
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
			SDL_SetRenderDrawColor(v->ren, 140, 140, 140, 255);
		}
	}
	sky = HEIGHT / 2;
	while (++sky <= HEIGHT)
	{
		land = -1;
		while (++land <= WIDTH)
		{
			SDL_RenderDrawPoint(v->ren, land, sky);
			SDL_SetRenderDrawColor(v->ren, 179, 179, 179, 255);
		}
	}
}

void			movement(t_env *v, int *ix, int *iy, int *jx, int *jy)
{
	const Uint8 *key = SDL_GetKeyboardState(NULL);
	if (key[SDL_SCANCODE_DOWN])
	{
		//SDL_RenderClear(v->ren);
		//background(v);
		SDL_SetRenderDrawColor(v->ren, 0, 0, 0, 255);
		SDL_RenderClear(v->ren);
		*jy += 10;
		*iy += 10;
		my_sdl_drawline(make_spot(*ix, *iy), make_spot(*jx, *jy), make_rgb(255, 255, 255, 225), v);
	}
	if (key[SDL_SCANCODE_UP])
	{
		//SDL_RenderClear(v->ren);
		//background(v);
		SDL_SetRenderDrawColor(v->ren, 0, 0, 0, 255);
		SDL_RenderClear(v->ren);
		*jy -= 10;
		*iy -= 10;
		my_sdl_drawline(make_spot(*ix, *iy), make_spot(*jx, *jy), make_rgb(255, 255, 255, 225), v);
	}
	if (key[SDL_SCANCODE_RIGHT])
	{
		//SDL_RenderClear(v->ren);
		//background(v);
		SDL_SetRenderDrawColor(v->ren, 0, 0, 0, 255);
		SDL_RenderClear(v->ren);
		*jx += 10;
		*ix += 10;
		my_sdl_drawline(make_spot(*ix, *iy), make_spot(*jx, *jy), make_rgb(255, 255, 255, 225), v);
	}
	if (key[SDL_SCANCODE_LEFT])
	{
		//SDL_RenderClear(v->ren);
		//background(v);
		SDL_SetRenderDrawColor(v->ren, 0, 0, 0, 255);
		SDL_RenderClear(v->ren);
		*jx -= 10;
		*ix -= 10;
		my_sdl_drawline(make_spot(*ix, *iy), make_spot(*jx, *jy), make_rgb(255, 255, 255, 225), v);
	}
}

int				main(int av, char **ac)
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
	make_map(v, fd);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error("Couldn't initialize SDL");
	v->win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	if (v->win == NULL)
		ft_error("Could not create the window");
	v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE);
	if (v->ren == NULL)
		ft_error("Could not create a renderer");

	raycasting(v);

	int			ix = 200;
	int			iy = 100;
	int			jx = 500;
	int			jy = 400;
	while (1)
	{
		//background(v);
		SDL_SetRenderDrawColor(v->ren, 0, 0, 0, 255);
		my_sdl_drawline(make_spot(ix, iy), make_spot(jx, jy), make_rgb(255, 255, 255, 225), v);
		if (SDL_PollEvent(&event))
		{
			const Uint8 *key = SDL_GetKeyboardState(NULL);
			if (event.type == SDL_QUIT)
				break;
			if (key)
				movement(v, &ix, &iy, &jx, &jy);
			SDL_RenderPresent(v->ren);
		}
	}
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
	return (0);
}
