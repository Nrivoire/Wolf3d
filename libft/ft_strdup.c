/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:32:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 14:32:18 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*dest;

	dest = 0;
	i = 0;
	i = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
