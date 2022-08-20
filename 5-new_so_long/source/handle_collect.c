/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:19:33 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 20:53:49 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	colect_w(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i - 1][j] = '0';
		game->total_collectible--;
		check_chest(game);
	}
}

void	colect_s(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i + 1][j] = '0';
		game->total_collectible--;
		check_chest(game);
	}
}

void	colect_a(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i][j - 1] = '0';
		game->total_collectible--;
		check_chest(game);
	}
}

void	colect_d(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i][j + 1] = '0';
		game->total_collectible--;
		check_chest(game);
	}
}

void	check_chest(t_data *game)
{
	if (game->total_collectible == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->exit);
		game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
				"images/chest_open.xpm", &game->width, &game->height);
	}
}
