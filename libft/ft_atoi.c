/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 15:31:06 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 19:59:17 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Son fonctionnement =
** La fonction atoi convertit le debut de la chaine de caracteres
** pointee par str en entier de type int. (Selon la table ASCII)
**
** Le retour =
** Le int trouvé avec son signe negatif si necessaire.
**
** Cas d'erreurs =
** Sa particularite est que atoi ne detecte pas d'erreurs.
**
** Sa logique =
** 1) Tu saute les cas frtnrv et l'espace
** 2) Tu regarde si c'est un negatif
** 3) Tu sautes les signes en trop
** 4) Tant que ton charactere est entre 0 et 9 dans la table ASCII :
**	- Tu transforme ton caractere en nombre
**	- Tu passes au dixaines
**	- Tu continu dans ta chaine de caracteres
** 5) Tu retourne le nombre avec son signe
*/

int		ft_atoi(char *str)
{
	int nb;
	int negatif;
	int i;

	i = 0;
	negatif = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45)
		negatif = 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10;
		nb += ((int)str[i] - 48);
		i++;
	}
	if (negatif == 1)
		return (-nb);
	else
		return (nb);
}
