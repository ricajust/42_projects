/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:08:08 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 21:27:54 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_shape(t_data *game, int j, int length)
{
	if (j != length)
		error_shape(game);
}

void	check_map_pointer(t_data *game)
{
	if (!(game->map[0]))
		error_pointer(game);
}

void	check_items(t_data *game, int i)
{
	int	j;
	int	others;

	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'C')
			game->total_collectible++;
		else if (game->map[i][j] == 'P')
			game->total_player++;
		else if (game->map[i][j] == 'E')
			game->total_exit++;
		else if (game->map[i][j] == '0' || game->map[i][j] == '1')
			others++;
		else
			error_items(game, game->map[i][j]);
		j++;
	}
}

void	check_items_size(t_data *game)
{
	if (game->total_player != 1)
		error_size_items(game, 'p');
	else if (game->total_exit != 1)
		error_size_items(game, 'e');
	else if (game->total_collectible == 0)
		error_size_items(game, 'c');
}

void	check_walls(t_data *game)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = game->row - 1;
	column = game->column - 1;
	while (game->map[0][i] && game->map[row][i])
	{
		if (game->map[0][i] != '1' || game->map[row][i] != '1')
			error_walls(game, 'v');
		i++;
	}
	i = 0;
	while (i < game->row)
	{
		if (game->map[i][0] != '1' || game->map[i][column] != '1')
			error_walls(game, 'h');
		i++;
	}
}
