/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 07:50:58 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/10 21:24:41 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	number;

	number = 42;
	puts("\n\nAqui inicia o print\n");
	ft_printf(" %u \n\n", number);
	printf(" %u ", number);
	puts("\n\nAqui finaliza a bagaça!\n\n");
	return (0);
}
