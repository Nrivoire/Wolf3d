/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_bits.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 17:27:01 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 17:27:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int oct;
	int bit;

	bit = 128;
	oct = octet;
	while (bit != 0)
	{
		if (oct >= bit)
		{
			ft_putchar('1');
			oct = oct % bit;
		}
		else
			ft_putchar('0');
		bit = bit / 2;
	}
}
