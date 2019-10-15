/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 14:18:06 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 18:39:12 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = (char *)dest;
	s = (const char *)src;
	if (s < d)
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	else if (d != s)
		ft_memcpy(dest, src, n);
	return (dest);
}
