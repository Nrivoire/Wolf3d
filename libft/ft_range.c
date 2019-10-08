/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 16:47:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 16:48:08 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int n;
	int *e;

	n = 0;
	if (min >= max)
		return (NULL);
	else
		e = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		e[n] = min;
		n++;
		min++;
	}
	return (e);
}
