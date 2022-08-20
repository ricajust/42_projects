/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:07:35 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 20:48:27 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprites(t_data *game)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/ground.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/tree.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/samurai_down.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/chest_close.xpm", &x, &y);
	game->collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/key.xpm", &x, &y);
}

void	put_image(t_data *game, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall,
			(32 * game->j), (32 * game->i));
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
			(32 * game->j), (32 * game->i));
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit,
			(32 * game->j), (32 * game->i));
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible,
			(32 * game->j), (32 * game->i));
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor,
			(32 * game->j), (32 * game->i));
	else if (tile == 'F')
	{
		error_items(game, '#');
		close_game(game);
		exit(1);
	}
}

void	render(t_data *game)
{
	game->i = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (game->i < game->row)
	{
		game->j = 0;
		while (game->j < game->column)
		{
			if (game->map[game->i][game->j] == '1')
				put_image(game, '1');
			else if (game->map[game->i][game->j] == 'P')
				put_image(game, 'P');
			else if (game->map[game->i][game->j] == 'E')
				put_image(game, 'E');
			else if (game->map[game->i][game->j] == 'C')
				put_image(game, 'C');
			else if (game->map[game->i][game->j] == '0')
				put_image(game, '0');
			else
				put_image(game, 'F');
			game->j++;
		}
		game->i = game->i + 1;
	}
}
