/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:48:07 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 14:29:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str = (char *)s;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	while (str[len - 1] && ft_iswhitespace(str[len - 1]))
		len--;
	len = i > len ? 1 : (len - i);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strsub(s, i, len);
	str[len] = '\0';
	return (str);
}
