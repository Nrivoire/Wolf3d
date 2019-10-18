/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_parsing.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:56:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 19:32:49 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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

static size_t	ft_count_map(char const *s, char c)
{
	size_t	i;
	size_t	j;

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

void		check_map(t_env *v, char *line)
{
	int		i;
	int		n;
	int		nb_col;

	i = 0;
	n = 0;
	nb_col = 0;
	while (line[i] != '\0')
	{
		nb_col++;
		if (line[i] == '1' || line[i] == '0' || (line[i] == '-' && line[i + 1] == '1') || line[i] == ' ')
		{
			if (line[i] == '-' && line[i + 1] == '1')
				n++;
			if (n > 1)
				ft_error("A - The map is not valid.");
			i++;
		}
		else
			ft_error("B - The map is not valid.");
	}
	if (v->col == 0)
		v->col = ft_count_map(line, ' ');
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

void		free_tab(char **tab, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_strdel(&tab[i]);
	free(tab);
}

void		make_map(t_env *v, int fd)
{
	t_lst	*lst;
	int		map_r;
	int		map_c;
	int		i;
	char	**s;

	map_r = 0;
	lst = wolf3d_parsing(v, fd);
	if (!(v->map = malloc(sizeof(int *) * (v->row + 2))))
		return ;
	i = -1;
	while (++i < v->row + 2)
		if (!(v->map[i] = malloc(sizeof(int) * (v->col + 2))))
			return ;
	while (lst != NULL && ++map_r < v->row + 1)
	{
		map_c = 0;
		i = -1;
		if (!(s = ft_strsplit(lst->line, ' ')))
			ft_error("Error");
		while (++map_c < v->col + 1)
		{
			if (ft_atoi(s[++i]) < 0)
			{
				if (v->pos.pos.y != -1 && v->pos.pos.y != -1)
					ft_error("There should be only one -1 in the map.");
				v->pos.pos.y = map_r + 0.5;
				v->pos.pos.x = map_c + 0.5;
				v->map[map_r][map_c] = 0;
			}
			else
				v->map[map_r][map_c] = ft_atoi(s[i]);
		}
		free_tab(s, v->col);
		lst = lst->next;
	}
	i = -1;
	while (++i < v->col + 2)
	{
		v->map[0][i] = 1;
		v->map[v->row + 1][i] = 1;
	}
	i = -1;
	while (++i < v->row + 2)
	{
		v->map[i][0] = 1;
		v->map[i][v->col + 1] = 1;
	}

	//i = -1;
	//register int j;
	//while (++i < v->row + 2)
	//{
	//	j = -1;
	//	while (++j < v->col + 2)
	//	{
	//		printf("%d ", v->map[i][j]);
	//	}
	//	printf("\n");
	//}
}
