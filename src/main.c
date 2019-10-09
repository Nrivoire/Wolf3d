/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:09:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 13:43:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void			free_env(t_env *v)
{
	if (v)
	{
		if (v->mlx)
		{
			if (v->mlx->mlx_ptr)
				free(v->mlx->mlx_ptr);
			if (v->mlx->win_ptr)
				free(v->mlx->win_ptr);
			free(v->mlx);
		}
		if (v->img)
		{
			if (v->img->ptr)
				free(v->img->ptr);
			if (v->img->img_tmp)
				free(v->img->img_tmp);
			if (v->img->img)
				free(v->img->img);
			free(v->img);
		}
	}
}

void			refresh_display(t_env *v)
{
	int			i;
	int			j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			ft_pixel_put(v->mlx->img, j, i, 0);
	}
}

int     main(int av, char **ac)
{
    t_env		*v;
	int			fd;

	fd = -1;
	if (av != 2 || (fd = open(ac[1], O_RDONLY)) < 0)
		ft_error("usage: ./wolf3d map");
	if (!(v = ft_memalloc(sizeof(t_env))))
		ft_error("struct t_env ft_memalloc error");
	v->col = 0;
	v->row = 0;
	make_map(v, fd);
	if (!(v->mlx = ft_memalloc(sizeof(t_mlx))))
		ft_error("struct t_mlx ft_memalloc error");
    v->mlx->mlx_ptr = mlx_init();
	v->mlx->win_ptr = mlx_new_window(v->mlx->mlx_ptr, WIDTH, HEIGHT, "wolf3d");
    ft_create_img(v->mlx->mlx_ptr, &v->mlx->img, WIDTH, HEIGHT);
    mlx_loop(v->mlx->mlx_ptr);
    return (0);
}
