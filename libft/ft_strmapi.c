/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:38:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 15:46:15 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (str != '\0' && f != '\0')
	{
		if (!(str = ft_strdup(str)))
			return (NULL);
		while (str[i] != '\0')
		{
			str[i] = f(i, str[i]);
			i++;
		}
		return (str);
	}
	return (0);
}
