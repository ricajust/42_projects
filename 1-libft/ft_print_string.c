/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:02:38 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/10 21:23:11 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_print_character(str[i]);
			i++;
		}
		return (i);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}
