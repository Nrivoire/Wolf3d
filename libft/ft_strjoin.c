/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 12:45:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/23 03:59:08 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** La fonction Strjoin alloue dans une zone de memoire dynamique avec <malloc>
** et retourne une chaine de caracteres "fraiche" terminee par un '\0'
** resultant de la concanetation de s1 et s2.
**
** Le retour =
** La chaine de caractere "fraiche" resultant de la
** concanetation des deux chaines.
**
** Cas d'erreurs =
** Si l'allocation echoue, la fonction renvoie NULL.
** Si s1 et s2 n'existent pas, on renvoie 0. -> pour proteger la fonction
**
** Son utilite =
** Permet de concatener deux chaines de caracteres sans
** ecraser les chaines
** de caracteres s1 et s2 car creation d'une toute nouvelle chaine
** de caracteres.
**
** Exemple =
** s1 : Je suis une patate
** s2 :  toute douce et violette.
** resultat : Je suis une patate toute douce et violette.
*/

char	*ft_strjoin(char const *dest, char const *src)
{
	size_t	n;
	char	*res;

	if (dest && src)
	{
		n = (ft_strlen(dest) + ft_strlen(src)) + 1;
		if (!(res = (char *)malloc(sizeof(char) * n)))
			return (NULL);
		ft_strcpy(res, (char *)dest);
		ft_strcat(res, src);
		return (res);
	}
	return (0);
}
