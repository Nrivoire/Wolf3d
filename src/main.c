/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:09:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 18:42:37 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		make_rad(t_env *v)
{
	int			i;

	i = -1;
	while (++i <= 1080)
		v->rad[i] = (i - 360) * (M_PI / 180);
}

static void		init(t_env *v)
{
	if (WIDTH < 0 || WIDTH > 2000 || HEIGHT < 0 || HEIGHT > 2000)
		ft_error("Incorrect window size\n");
	pthread_mutex_init(&v->mutex, NULL);
	v->pos.fov = (abs(FIELDOFVIEW) > 180) ? 360 : abs(FIELDOFVIEW);
	v->pos.angle = 90;
	v->rot_speed = (fabs(ROTSPEED) > 0.5) ? 0.5 : fabs(ROTSPEED);
	v->m_speed = (fabs(MOVESPEED) > 0.5) ? 0.5 : fabs(MOVESPEED);
	make_rad(v);
	assigntextures(v);
	v->col = 0;
	v->row = 0;
	v->pos.pos.y = -1;
	v->pos.pos.x = -1;
	v->bool_cam = 1;
	v->inc = -1;
}

static void		free_env(t_env *v)
{
	int			i;
	int			j;

	i = -1;
	if (v)
	{
		if (*v->sur)
		{
			while (++i < 9 && (j = -1))
				while (++j < 4)
					SDL_FreeSurface(v->sur[i][j]);
		}
		i = -1;
		if (v->map)
		{
			while (++i < v->row + 2)
				free(v->map[i]);
			free(v->map);
		}
		free(v);
	}
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
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error("Couldn't initialize SDL");
	if (!(v->win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0)))
		ft_error("Could not create the window");
	if (!(v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE)))
		ft_error("Could not create a renderer");
	if (!(v->back = SDL_CreateTexture(v->ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)))
		ft_error("Could not create a background texture");
	background(v);
	display(v);
	free_env(v);
	return (0);
}
