/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:52:53 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/18 07:19:35 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_core(va_list ap, const char *str)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (ft_strchr("cspdiuxX%%", str[i + 1]))
			{
				i++;
				length = length + ft_filter_flags(ap, str[i]);
			}
			else
				length = length + ft_putchar_plus(str[i]);
		}
		else if (str[i] != '%')
			length = length + ft_putchar_plus(str[i]);
		i++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				total_characters;

	va_start(ap, format);
	total_characters = ft_printf_core(ap, format);
	va_end(ap);
	return (total_characters);
}
