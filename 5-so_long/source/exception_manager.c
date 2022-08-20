/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:04:15 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 21:28:25 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_pointer(t_data *game)
{
	ft_printf("Error\nMap file invalid, please choose another file\n");
	free_matrix(game);
	exit(1);
}

void	error_items(t_data *game, char c)
{
	ft_printf("Error\nInvalid map, character (%c) not allowed!\n", c);
	free_matrix(game);
	exit(1);
}

void	error_shape(t_data *game)
{
	ft_printf("Error\nMap invalid, please check rows length\n");
	free_matrix(game);
	exit(1);
}

void	error_size_items(t_data *game, char flag)
{
	if (flag == 'p')
		ft_printf("Error\nNumber of player in map is invalid\n");
	else if (flag == 'c')
		ft_printf("Error\nNumber of collectible in map is invalid\n");
	else
		ft_printf("Error\nNumber of exit in map is invalid\n");
	free_matrix(game);
	exit(1);
}

void	error_walls(t_data *game, char flag)
{
	if (flag == 'h')
		ft_printf("Error\nThe map isn't surrounded by walls in vertical \n");
	else
		ft_printf("Error\nThe map isn't surrounded by walls in horizontal \n");
	free_matrix(game);
	exit(1);
}
