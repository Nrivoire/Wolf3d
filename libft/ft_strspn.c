/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strspn.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 15:37:21 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:44:43 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** Calcule la longueur du segment initial de s qui ne contient que des
** caracteres presents dans accept.
**
** Le retour =
** renvoie le nombre de caracteres dans s qui sont presents dans accept
**
** Exemple =
** s : 123
** accept : 2661663
** retour : 3
*/

size_t		ft_strspn(const char *s, const char *accept)
{
	size_t		nb;

	nb = 0;
	while (*s && (ft_strchr(accept, *s++) != NULL))
		nb++;
	return (nb);
}
