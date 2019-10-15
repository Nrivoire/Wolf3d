/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_natoi.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 01:10:47 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 01:13:18 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_natoi(char *str, size_t start)
{
	int nb;
	int negatif;

	negatif = 0;
	nb = 0;
	while ((str[start] >= 9 && str[start] <= 13) || (str[start] == 32))
		start++;
	if (str[start] == 45)
		negatif = 1;
	if (str[start] == 45 || str[start] == 43)
		start++;
	while (str[start] >= 48 && str[start] <= 57)
	{
		nb = nb * 10;
		nb += ((int)str[start] - 48);
		start++;
	}
	if (negatif == 1)
		return (-nb);
	else
		return (nb);
}
