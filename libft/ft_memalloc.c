/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 20:49:41 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 14:56:57 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue et retourne une zone de mémoire "fraiche".
** La mémoire allouée est initiaisée à zéro.
** Si l'allocation échoue, la fonction renvoie NULL.
** Memalloc renvoir la zone de mémoire allouée avec un malloc.
**
** Son utilité?
** Allouer de la mémoire dynamique ("flexible"),
** et aussi à créer une zone de mémoire accessible
** à n'importe quelle endroit du programme.
*/

void	*ft_memalloc(size_t size)
{
	void	*me;

	if (!(me = malloc(sizeof(size_t) * size)))
		return (NULL);
	me = ft_memset(me, 0, size);
	return (me);
}
