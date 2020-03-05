/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 13:43:47 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 16:01:51 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		free_tab(char **tab, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_strdel(&tab[i]);
	free(tab);
}

static void		make_map(int map_c, int map_r, char **s, t_env *v)
{
	if (ft_atoi(s[++v->inc]) < 0)
	{
		if (v->pos.pos.y != -1 && v->pos.pos.y != -1)
			ft_error("There should be only one -1 in the map.");
		v->pos.pos.y = map_r + 0.5;
		v->pos.pos.x = map_c + 0.5;
		v->map[map_r][map_c] = 0;
	}
	else
		v->map[map_r][map_c] = ft_atoi(s[v->inc]);
}

static void		lstdel(t_lst *lst)
{
	if (lst->next)
		lstdel(lst->next);
	ft_strdel(&lst->line);
	free(lst);
}

static void		outline(t_env *v, t_lst *begin)
{
	if (v->pos.pos.y == -1 && v->pos.pos.y == -1)
		ft_error("There should be at least one -1 in the map.");
	lstdel(begin);
	v->inc = -1;
	while (++v->inc < v->col + 2)
	{
		v->map[0][v->inc] = 1;
		v->map[v->row + 1][v->inc] = 1;
	}
	v->inc = -1;
	while (++v->inc < v->row + 2)
	{
		v->map[v->inc][0] = 1;
		v->map[v->inc][v->col + 1] = 1;
	}
}

void			map(t_env *v)
{
	t_lst	*begin;
	int		map_r;
	int		map_c;
	char	**s;

	map_r = 0;
	begin = v->lst;
	if (!(v->map = malloc(sizeof(int *) * (v->row + 2))))
		return ;
	while (++v->inc < v->row + 2)
		if (!(v->map[v->inc] = malloc(sizeof(int) * (v->col + 2))))
			return ;
	while (v->lst != NULL && ++map_r < v->row + 1)
	{
		map_c = 0;
		v->inc = -1;
		if (!(s = ft_strsplit(v->lst->line, ' ')))
			ft_error("Error");
		while (++map_c < v->col + 1)
			make_map(map_c, map_r, s, v);
		free_tab(s, v->col);
		v->lst = v->lst->next;
	}
	outline(v, begin);
}
