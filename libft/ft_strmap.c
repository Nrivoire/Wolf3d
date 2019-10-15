/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 13:00:55 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:08:15 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** Applique la fonction f à chaque caractère de la chaine de caractère
** passée en paramètre pour creéer une nouvelle chaine "fraiche" (avec malloc)
** resultant des applications successives de f.
**
** Le retour =
** La nouvelle chaine de caractere resultant de l'application de la
** fonction sur chaque caracteres.
**
** Cas d'erreurs =
** Si l'allocation dynamique ne fonctionne pas, la fonction retourne NULL.
*/

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[i] = f(str[i]);
			i++;
		}
		return (str);
	}
	return (0);
}
