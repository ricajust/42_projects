/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:57:41 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 21:18:58 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_right(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/samurai_right.xpm", &game->width, &game->height);
	move_d(game);
}

void	walk_left(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/samurai_left.xpm", &game->width, &game->height);
	move_a(game);
}

void	walk_down(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/samurai_down.xpm", &game->width, &game->height);
	move_s(game);
}

void	walk_up(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/samurai_up.xpm", &game->width, &game->height);
	move_w(game);
}
