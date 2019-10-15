/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 12:45:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:12:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** La fonction Strsub alloue une zone de memoire dynamique avec un <malloc>
** et retourne la copie "fraiche" d'un bout de la chaine de caracteres 's'.
** Le morceau selectionnee commence a 'start' et a pour longueur 'len'.
**
** Le retour =
** Elle renvoie le troncon selectionner.
**
** Cas d'erreurs =
** Si 'start' et 'len' ne designent pas un troncon de chaine valide,
** le comportement de la fonction est indeterminee. Si l'allocation echoue la
** fonction renvoie NULL.
**
** Utilite = Pouvoir copier et transformer un bout d'une chaine de caracteres
** deja existante en une autre chaine de caractere qui egalemment
** termine par un '\0'
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;

	i = 0;
	if (s)
	{
		if (!(res = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len && s && res)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
