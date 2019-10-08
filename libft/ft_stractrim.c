/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stractrim.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 12:06:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 16:14:43 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_stractrim(const char *str, const char c)
{
	char	*new;
	int		i;

	if (!(c && str && (new = (char*)malloc(sizeof(*new) * 	\
						(ft_strlen(str) - ft_occur(str, c) + 1)))))
		return (NULL);
	i = 0;
	if (*str != c)
		new[i] = *str;
	while (*++str)
		if (*str != c)
			new[++i] = *str;
	new[++i] = '\0';
	return (new);
}
