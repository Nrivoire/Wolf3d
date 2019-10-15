/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 03:57:33 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/25 01:42:26 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *dest, char *src)
{
	char	*res;

	res = ft_strjoin(dest, src);
	ft_strdel(&dest);
	ft_strdel(&src);
	return (res);
}
