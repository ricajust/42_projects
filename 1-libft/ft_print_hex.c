/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:08:39 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/10 21:11:30 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_hex_lower(int n)
{
	if (n <= 9)
		ft_putchar_plus(n + 48);
	else
		ft_putchar_plus(n + 87);
	return ;
}

static void	ft_print_hex_upper(int n)
{
	if (n <= 9)
		ft_putchar_plus(n + 48);
	else
		ft_putchar_plus(n + 55);
	return ;
}

static int	ft_aux(unsigned int nbr, int xorX)
{
	int	length;

	length = 1;
	if (xorX == 0 && nbr != 0)
	{	
		length = length + ft_aux(nbr / 16, 0);
		ft_print_hex_upper(nbr % 16);
	}
	else if (nbr != 0)
	{
		length = length + ft_aux(nbr / 16, 1);
		ft_print_hex_lower(nbr % 16);
	}
	return (length);
}

int	ft_print_hex(unsigned int nbr, int xorX)
{
	if (nbr == 0)
		return (ft_putchar_plus('0'));
	else
		return (ft_aux(nbr, xorX) - 1);
}
