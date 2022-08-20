/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 07:46:30 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 21:24:33 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	clear_allocated_vars(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_matrix(game);
	free(game->mlx_ptr);
}

int	close_game(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->floor);
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_image(game->mlx_ptr, game->player);
	mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_image(game->mlx_ptr, game->collectible);
	clear_allocated_vars(game);
	exit(1);
}
