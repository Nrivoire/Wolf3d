/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:59:26 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 14:16:33 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	void	*s;

	i = 0;
	s = (void *)src;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)s)[i];
			return (&dest[i + 1]);
		}
		((unsigned char *)dest)[i] = ((unsigned char *)s)[i];
		i++;
	}
	return (NULL);
}
