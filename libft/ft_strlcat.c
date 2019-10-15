/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 20:59:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 15:49:05 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lsrc;
	size_t	ldest;
	size_t	i;

	lsrc = ft_strlen(src);
	ldest = ft_strlen(dest);
	i = ldest;
	if (size <= ldest)
		return (lsrc + size);
	while (*src && i < size - 1)
	{
		dest[i++] = *src;
		src++;
	}
	dest[i] = '\0';
	return (ldest + lsrc);
}
