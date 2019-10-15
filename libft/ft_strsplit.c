/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 17:40:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 00:44:20 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** Alloue (avec un malloc) et retourne un tableau de chaine de caracteres
** "fraiches". Toutes les chaines de caracteres doivent etre terminees
** par un \0 et le tableau doit lui meme avoir un \0 pour sa derniere ligne.
** La decoupe des mots se fait en fonction d'un caractere predefini par
** l'utilisateur qu'on definira par c.
**
** Le retour =
** Retourne un tableau de chaines de caracteres "fraiches".
** Pour visualiser mieux : chaque mots trouvés se retrouvent sur une "ligne"
** ou plutot sur un tableau different du mot suivant jusqu'au \0 du tab.
*/

static size_t	ft_count_words(char const *s, char c)
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

static char		*ft_count_letters(char const *s, char c)
{
	size_t	i;
	size_t	n;
	char	*tab;

	n = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		n++;
	}
	if (!(tab = ft_memalloc(n + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	nb;
	char	**tab;

	i = 0;
	nb = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
			i++;
		else
		{
			tab[nb] = ft_count_letters(s + i, c);
			while (s[i] != c && s[i] != '\0')
				i++;
			nb++;
		}
	}
	tab[nb] = NULL;
	return (tab);
}
