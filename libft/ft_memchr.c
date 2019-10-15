/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 19:13:34 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 14:10:10 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	void		*s;

	i = 0;
	s = (void *)str;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
