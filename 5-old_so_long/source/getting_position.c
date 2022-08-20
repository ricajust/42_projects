/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:36:42 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 16:45:05 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_function_map(t_data *game, char tag)
{
	if (tag == 'F')
	{
		printf("Error\nPlease check the File Descriptor\n");
		mlx_destroy_display(game->mlx_ptr);
		close(game->file_descriptor);
		free(game->mlx_ptr);
		exit(1);
	}
	if (tag == 'G')
	{
		printf("Error\nPlease check the function Open (GNL)\n");
		mlx_destroy_display(game->mlx_ptr);
		close(game->file_descriptor);
		exit(1);
	}
}

void	create_window(t_data *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->x_axis * 50),
			(game->y_axis * 50), "So Long Game");
}

void	*y_axis_length(t_data *game)
{
	char	*gnl;

	game->file_descriptor = open(game->file_path, O_RDONLY);
	if (game->file_descriptor < 0)
		error_function_map(game, 'F');
	gnl = ft_get_next_line(game->file_descriptor);
	if (gnl == NULL)
		error_function_map(game, 'G');
	while (gnl)
	{
		game->y_axis = game->y_axis + 1;
		free(gnl);
		gnl = ft_get_next_line(game->file_descriptor);
	}
	create_window(game);
	free(gnl);
	close(game->file_descriptor);
	return (0);
}

void	x_axis_length(t_data *game)
{
	char	*gnl;

	game->file_descriptor = open(game->file_path, O_RDONLY);
	if (game->file_descriptor < 0)
		error_function_map(game, 'F');
	gnl = ft_get_next_line(game->file_descriptor);
	if (gnl == NULL)
		error_function_map(game, 'G');
	while (gnl)
	{
		game->x_axis = ft_strlen(gnl);
		free(gnl);
		gnl = ft_get_next_line(game->file_descriptor);
	}
	close(game->file_descriptor);
}
