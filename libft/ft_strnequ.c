/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 12:46:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 19:34:35 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (s1 && s2)
	{
		while (i < (n - 1) && (s1[i] == s2[i]) && s1[i] && s2[i])
			i++;
		if (n == 0)
			return (1);
		if ((s1[i] - s2[i]) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
