/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strequ.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 12:46:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 19:37:40 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] == s2[i]) && s1[i] && s2[i])
			i++;
		if ((s1[i] - s2[i]) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
