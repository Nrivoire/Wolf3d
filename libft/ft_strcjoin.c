/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:55:00 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 12:41:37 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** La fonction Strcjoin alloue une nouvelle chaine de caracteres
** dans une zone de memoire dynamique avec <malloc>
** et retourne une chaine de caracteres "fraiche" terminee par un '\0'
** jusqu'au caractere c resultant de la concanetation de s1 et s2.
**
** Le retour =
** La chaine de caractere "fraiche" resultant de la copie de dest +
** la concanetation de la source jusqu'au caractere c.
**
** Cas d'erreurs =
** Si l'allocation echoue, la fonction renvoie NULL.
** Si s1 et s2 n'existent pas, on renvoie 0. -> pour proteger la fonction
**
** Son utilite =
** Permet de concatener deux chaines de caracteres sans
** ecraser les chaines de caracteres s1 et s2 car
** creation d'une toute nouvelle chaine de caracteres.
**
** Exemple =
** c : \n
** s1 :J'aime cuisiner quand il fait beau
** s2 :	des paquerettes\n multicolores.
** resultat : J'aime cuisiner quand il fait beau des paquerettes.
*/

char	*ft_strcjoin(char const *dest, char const *src, char c)
{
	char	*res;
	int		n;

	if (dest && src && c)
	{
		n = ft_strlen(dest) + ft_strlen(ft_strchr(src, c)) + 1;
		if (!(res = (char *)malloc(sizeof(char) * n)))
			return (NULL);
		ft_strcpy(res, (char *)dest);
		ft_strcat(res, ft_strchr(src, c));
		return (res);
	}
	return (0);
}
