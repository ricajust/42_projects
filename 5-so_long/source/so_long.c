/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:36:51 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/17 21:59:44 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_expose(t_data *game)
{
	render(game);
	return (1);
}

void	initialize_vars(t_data *game)
{
	game->x_axis = 0;
	game->y_axis = 0;
	game->moviment = 0;
}

int	main(int argc, char *argv[])
{
	t_data		game;

	input_validation(argc, argv[1], &game);
	initialize_vars(&game);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (1);
	x_axis_length(&game);
	y_axis_length(&game);
	get_map(&game);
	check_collectible(&game);
	check_map(&game);
	put_sprites(&game);
	render(&game);
	mlx_key_hook(game.win_ptr, key_release, &game);
	mlx_hook(game.win_ptr, 33, 1L << 5, closee, &game);
	mlx_expose_hook(game.win_ptr, ft_expose, &game);
	mlx_loop(game.mlx_ptr);
}
