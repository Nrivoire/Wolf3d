/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:13:30 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 14:57:22 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** La fonction Memset remplace ou remplit les 'n' premiers
** octets de la zone mémoie pointée par 's'.
** Memset est une fonction qui renvoit un poiteur sur la zone mémoire
** pointée par 's'.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mem;

	mem = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		mem[i] = (unsigned char)c;
		i++;
	}
	return (mem);
}
