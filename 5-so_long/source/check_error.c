/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:35:13 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 16:56:45 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_all(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_matrix(game);
	free(game->mlx_ptr);
	exit(1);
}

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

int	closee(t_data *game)
{
	mlx_destroy_image(game->mlx_ptr, game->floor);
	mlx_destroy_image(game->mlx_ptr, game->tree);
	mlx_destroy_image(game->mlx_ptr, game->player);
	mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_image(game->mlx_ptr, game->collectible);
	reset_all(game);
	exit(1);
}

void	input_validation(int argc, char *file_path, t_data *game)
{
	char	*error_name;
	int		i;

	i = 0;
	if (argc != 2)
	{
		printf("\nError\nInvalid number of arguments (only one accepted)\n");
		exit(1);
	}
	i = ft_strlen(file_path);
	error_name = ft_strnstr(file_path, ".ber", i);
	if (error_name == NULL)
	{
		printf("\nError\nPlease check the name .ber!\n");
		exit(1);
	}
	else
	{
		game->file_path = file_path;
	}
}

void	check_map_error(t_data *game)
{
	if (game->amount_player != 1)
		printf("\nError\nYou have %d players in your map, \n",
			game->amount_player);
	if (game->amount_exit != 1)
		printf("\nError\nYou have %d exits in your map\n",
			game->amount_exit);
	if (game->amount_collectible == 0)
		printf("\nError\nYou have %d collectibles in your map\n",
			game->amount_collectible);
	reset_all(game);
}
