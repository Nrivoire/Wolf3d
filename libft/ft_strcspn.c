/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:01:37 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 14:58:17 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** La fonction calcule la longueur du segment inintial de s
** qui ne contient que des caratères absents de reject
**
** Le retour =
** renvie le nombre de caractères du segment initial de s constitué
** uniquement de caractères absents de reject
**
** Exemple =
** s : fcba73
** reject : 123456789
** retour = 5
*/

size_t		ft_strcspn(const char *s, const char *reject)
{
	size_t		nb;

	nb = 0;
	while (*s && ((ft_strchr(reject, *s++) == NULL)))
		nb++;
	return (nb);
}
