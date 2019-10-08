/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 10:26:27 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:11:20 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** La focntion strstr chercher la premiere occurence de la sous-chaine
** to_find au sein de la chaine de caracteres str. Les caracteres '\0'
** de fin ne sont pas compares.
**
** Son retour =
** 1) Si la sous chaine rentree est = '\0' je retourne la
** chaine de caractere str en entiere.
** exemple =
** str = Les cacahuetes sont tres bonnes pour la sante.
** to_find = '\0'
** retourne = Les cacahuetes sont tres bonnes pour la sante.
** 2) Si la sous chaine est autre chose, et EST dans la chaine de caracteres
** str alors je retourne la sous chaine trouvee suivie du reste de la chaine
** de caractere str.
** exemple :
** str = Je suis une patate toute gentille et douce comme un chou.
** to_find = "gentille"
** retourne = gentille et douce comme un chou.
** 3) Si la sous chaine n'est pas retrouvee on retourne rien
*/

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
