/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_lst.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 12:04:32 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 12:24:27 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_lst(t_list *elem)
{
	if (elem)
	{
		ft_putstr((char *)elem->content);
		elem = elem->next;
		ft_putchar('\n');
	}
}
