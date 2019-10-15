/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 16:19:54 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 20:24:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_int(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				neg;
	unsigned int	nb;

	neg = 0;
	i = ft_count_int(n);
	if (n < 0)
		neg = 1;
	nb = n > 0 ? n : (n * (-1));
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i - 1 >= 0)
	{
		str[i - 1] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
