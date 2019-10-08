/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pixel_put.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 07:02:23 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 16:17:34 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_mlx_img img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= img.width || y >= img.height)
		return ;
	img.img[y * img.width + x] = color;
}
