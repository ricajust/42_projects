/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:41:50 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/20 14:24:08 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	input_validator(argc, argv[1], &game);
	reset_variables(&game);
	open_map_file(&game);
	tracker(&game);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
	{
		free_matrix (&game);
		exit (1);
	}
	create_window(&game);
	put_sprites(&game);
	render(&game);
	mlx_key_hook(game.win_ptr, key_release, &game);
	mlx_hook(game.win_ptr, 33, 1L << 5, close_game, &game);
	mlx_expose_hook(game.win_ptr, ft_expose, &game);
	mlx_loop(game.mlx_ptr);
	free(game.mlx_ptr);
	return (0);
}
