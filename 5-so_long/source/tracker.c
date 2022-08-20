/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 07:21:02 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 20:28:34 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Scans the matrix and performs some check functions
 * 
 * @param game game Struct
 */
void	tracker(t_data *game)
{
	int		i;
	int		j;
	int		length;

	check_map_pointer(game);
	j = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		length = ft_strlen(game->map[i]);
		check_shape(game, j, length);
		check_items(game, i);
		i++;
	}
	check_items_size(game);
	game->row = i;
	game->column = j;
	check_walls(game);
}
