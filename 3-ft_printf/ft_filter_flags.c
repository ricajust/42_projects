/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:40:27 by rda-silv          #+#    #+#             */
/*   Updated: 2022/04/10 22:06:51 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_filter_flags(va_list ap, int flag)
{
	int	length;

	length = 0;
	if (flag == 'c')
		length = ft_print_character(va_arg(ap, int));
	else if (flag == 's')
		length = ft_print_string(va_arg(ap, char *));
	else if (flag == 'p')
		length = ft_print_pointer(va_arg(ap, unsigned long));
	else if (flag == 'd' || flag == 'i')
		length = ft_print_decimal(va_arg(ap, int));
	else if (flag == 'u')
		length = ft_print_positive_int(va_arg(ap, unsigned int));
	else if (flag == 'x')
		length = ft_print_hex(va_arg(ap, unsigned int), 1);
	else if (flag == 'X')
		length = ft_print_hex(va_arg(ap, unsigned int), 0);
	else if (flag == '%')
		length = ft_putchar_plus('%');
	return (length);
}
