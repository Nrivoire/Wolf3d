/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 12:11:22 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 16:52:22 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_sq(int nb)
{
	return (nb * nb);
}

int		ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 0;
	while (ft_sq(++sqrt) < nb)
		if (sqrt > 46340)
			return (0);
	return (sqrt);
}
