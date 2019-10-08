/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:35:37 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 17:03:16 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str)
{
	size_t		n;
	size_t		i;
	char		*rev;

	i = 0;
	n = ft_strlen(str);
	if (!(rev = ft_strnew(ft_strlen(str))))
		return (NULL);
	if (!str)
		return (0);
	while (n > 0)
	{
		rev[i] = str[n - 1];
		i++;
		n--;
	}
	return (rev);
}
