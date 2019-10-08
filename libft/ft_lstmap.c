/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 18:16:41 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 15:49:21 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	if (lst && f)
	{
		map = f(lst);
		tmp = map;
	}
	while ((lst = lst->next))
	{
		map->next = f(lst);
		map = map->next;
	}
	return (tmp);
}
