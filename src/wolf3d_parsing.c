/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:56:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 14:45:43 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void		add_elem(t_lst **elem, char *line)
{
	t_lst	*new;
	t_lst	*tmp;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		ft_error("Error malloc lst");
	new->line = line;
	new->next = NULL;
	if (*elem == NULL)
		*elem = new;
	else
	{
		tmp = *elem;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		lstdel(t_lst *lst)
{
	if (lst->next)
		lstdel(lst->next);
	free(lst);
}

t_lst		*wolf3d_parsing(int fd)
{
	char	*line;
	t_lst	*lst;

	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		check_map(line);
		add_elem(&lst, line);
	}
	return (lst);
}

void		make_map(t_env *v, int fd)
{
	t_lst	*lst;
	int		row;
	int		column;
	int		i;

	i = -1;
	column = 0;
	lst = wolf3d_parsing(fd);
	if (!(v->map = malloc(sizeof(int) * )))
		return (NULL);
	while (lst->next != NULL)
	{
		row = -1;
		while (lst->line[++i] != '\0')
		{
			v->map[column][++row] = lst->line[i];
			printf("%2d", v->map[column][row]);
		}
		printf("\n");
		lst = lst->next;
		column++;
	}
}