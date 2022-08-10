/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_positive_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:24:36 by rda-silv          #+#    #+#             */
/*   Updated: 2022/04/13 08:42:13 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_positive_int(int number)
{
	char	*str;
	int		length;

	str = ft_uitoa(number);
	ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	free(str);
	return (length);
}
