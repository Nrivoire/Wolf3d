/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:56:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 14:01:22 by nrivoire    ###    #+. /#+    ###.fr     */
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

void		check_map(t_env *v, char *line)
{
	int		i;
	int		n;
	int		nb_col;

	i = 0;
	n = 0;
	nb_col++;
	while (line[i] != '\0')
	{
		nb_col++;
		if (line[i] == '1' || line[i] == '0' || line[i] == 'X')
		{
			if (line[i] == 'X')
				n++;
			if (n > 1)
				ft_error("The map is not valid.");
			i++;
		}
		else
			ft_error("The map is not valid.");
	}
	if (v->col == 0)
		v->col == nb_col;
	v->col = v->col >= nb_col ? v->col : nb_col;
}

t_lst		*wolf3d_parsing(t_env *v, int fd)
{
	char	*line;
	t_lst	*lst;

	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		v->row++;
		check_map(v, line);
		add_elem(&lst, line);
	}
	return (lst);
}

void		make_map(t_env *v, int fd)
{
	t_lst	*lst;
	int		map_r;
	int		map_c;
	int		i;

	i = -1;
	map_r = 0;
	lst = wolf3d_parsing(v, fd);
	if (!(v->map = malloc(sizeof(int) * (v->col * v->row + 1))))
		return (NULL);
	while (lst->next != NULL)
	{
		map_c = -1;
		while (lst->line[++i] != '\0')
		{
			v->map[map_r][++map_c] = lst->line[i];
			printf("%2d", v->map[map_r][map_c]);
		}
		printf("\n");
		lst = lst->next;
		map_r++;
	}
}