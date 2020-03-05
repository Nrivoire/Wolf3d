/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:56:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 16:02:51 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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

static void		check_map(t_env *v, char *line)
{
	int			i;
	int			nb_col;

	i = 0;
	nb_col = 0;
	while (line[i] != '\0')
	{
		nb_col++;
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-' &&
				line[i + 1] == '1') || line[i] == ' ')
		{
			if ((ft_atoi(&line[i]) >= 0 && ft_atoi(&line[i]) <= 9) ||
					(ft_atoi(&line[i]) == -1))
				i++;
			else
				ft_error("The map is not valid.");
		}
		else
			ft_error("The map is not valid.");
	}
	if (v->col == 0)
		v->col = ft_count_map(line, ' ');
	if (ft_count_map(line, ' ') != (size_t)v->col)
		ft_error("Not a valid map. The map must be a rectangle.");
}

static t_lst	*ft_lst_new(char *line, int line_size)
{
	t_lst		*elem;

	if (!(elem = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (line)
	{
		elem->line = ft_strnew(line_size);
		ft_memcpy(elem->line, line, line_size);
	}
	else
		elem->line = NULL;
	elem->next = NULL;
	return (elem);
}

static void		add_elem(t_lst **elem, char *line, int line_size)
{
	t_lst		*new;
	t_lst		*tmp;

	new = ft_lst_new(line, line_size);
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

t_lst			*wolf3d_parsing(t_env *v, int fd)
{
	char		*line;
	t_lst		*lst;

	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		v->row++;
		check_map(v, line);
		add_elem(&lst, line, ft_strlen(line));
		ft_strdel(&line);
	}
	return (lst);
}
