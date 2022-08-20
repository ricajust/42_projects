/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:37:20 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 16:55:52 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_right(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "image/right.xpm",
			&game->width, &game->height);
	move_d(game);
}

void	walk_left(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "image/left.xpm",
			&game->width, &game->height);
	move_a(game);
}

void	walk_down(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "image/down.xpm",
			&game->width, &game->height);
	move_s(game);
}

void	walk_up(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "image/up.xpm",
			&game->width, &game->height);
	move_w(game);
}
