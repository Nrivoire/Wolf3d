/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 16:44:08 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:39:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(elem->content = (void *)malloc(sizeof(content_size))))
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	else
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	elem->next = NULL;
	return (elem);
}
