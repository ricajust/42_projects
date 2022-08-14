/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:05:42 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 17:34:10 by rda-silv         ###   ########.fr       */
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

static int	ft_aux(unsigned long address)
{
	int	length;

	length = 1;
	if (address != 0)
	{
		length = length + ft_aux(address / 16);
		ft_print_hex_lower(address % 16);
	}
	return (length);
}

int	ft_print_pointer(unsigned long address)
{
	if (!address)
	{
		ft_print_string("(nil)");
		return (5);
	}
	if (address == 0)
	{
		ft_print_string("0x0");
		return (3);
	}
	else
	{
		ft_print_string("0x");
		return (ft_aux(address) + 1);
	}
	return (1);
}
