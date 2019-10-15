/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 03:15:34 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 03:16:41 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t start)
{
	while (s[start])
	{
		if (s[start] == c)
			return ((char *)s + start);
		start++;
	}
	if (s[start] == '\0' && c == '\0')
		return ((char *)s + start);
	return (0);
}
