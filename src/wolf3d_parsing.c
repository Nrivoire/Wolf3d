/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:56:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 13:52:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			add_elem(t_lst **elem, char *line)
{
	t_lst		*new;
	t_lst		*tmp;

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

static size_t	ft_count_map(char const *s, char c)
{
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			j = 1;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

void			check_map(t_env *v, char *line)
{
	int			i;
	int			n;
	int			nb_col;

	i = 0;
	n = 0;
	nb_col = 0;
	while (line[i] != '\0')
	{
		nb_col++;
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-' \
				&& line[i + 1] == '1') || line[i] == ' ')
		{
			if (line[i] == '-' && line[i + 1] == '1')
				n++;
			if (n > 1)
				ft_error("The map is not valid.");
			i++;
		}
		else
			ft_error("The map is not valid.");
	}
	if (v->col == 0)
		v->col = ft_count_map(line, ' ');
}

t_lst			*wolf3d_parsing(t_env *v, int fd)
{
	char		*line;
	t_lst		*lst;

	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		v->row++;
		check_map(v, line);
		add_elem(&lst, line);
	}
	return (lst);
}
