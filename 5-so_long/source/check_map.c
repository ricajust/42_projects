/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:35:21 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 14:35:21 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	define(t_data *game)
{
	if (game->amount_player == 1 && game->amount_exit == 1
		&& game->amount_collectible > 0)
		return (1);
	check_map_error(game);
	exit(1);
}

void	check_map(t_data *game)
{
	check_rectangle(game);
	check_wall(game);
	check_elements(game);
}

void	check_elements(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	game->amount_exit = 0;
	game->amount_collectible = 0;
	game->amount_player = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->amount_exit++;
			else if (game->map[i][j] == 'C')
				game->amount_collectible++;
			else if (game->map[i][j] == 'P')
				game->amount_player++;
			j++;
		}
		i++;
	}
	define(game);
}

void	check_rectangle(t_data *game)
{
	char	*first_line;
	int		row;

	first_line = game->map[0];
	row = 0;
	while (game->map[row])
	{
		if (ft_strlen(game->map[row]) != ft_strlen(first_line))
		{
			printf("Error\n Maps not rectangular. Please, check the map.\n");
			reset_all(game);
		}
		row++;
	}
}

void	check_wall(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\0' && game->map[game->y_axis - 1][i] !=
	'\0')
	{
		if (game->map[0][i] != '1' || game->map[game->y_axis - 1][i] !=
		'1')
		{
			printf("ERROR\nYou need to check the walls in the map.\n");
			reset_all(game);
		}
		i++;
	}
	i = 0;
	while (i < game->y_axis)
	{
		if (game->map[i][0] != '1' || game->map[i][game->x_axis - 1] !=
		'1')
		{
			printf("ERROR\nYou need to check the walls in the map.\n");
			exit(1);
		}
		i++;
	}
}
