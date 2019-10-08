/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_img.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 07:01:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 15:18:13 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_img(void *ptr, t_mlx_img *img, int w, int h)
{
	img->ptr = mlx_new_image(ptr, w, h);
	img->img = (unsigned int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l,
			&img->endian);
	img->width = w;
	img->height = h;
}
