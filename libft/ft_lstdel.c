/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 14:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 17:42:14 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*element;

	element = *alst;
	if (alst)
	{
		while (element != NULL)
		{
			del(element->content, element->content_size);
			free(element);
			element = element->next;
		}
		*alst = NULL;
	}
}
