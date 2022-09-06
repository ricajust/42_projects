/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:31:53 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/04 21:43:10 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_poc.h"

void	argc_validator(int argc)
{
	if (argc < 3)
	{
		printf("Error\n%d is insuficient argments, please try again\n!", argc);
		exit(-1);
	}
	else if (argc > 3)
	{
		printf("Error\n%d is too much argments, please try again\n!", argc);
		exit(-1);
	}
}
