/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:37:25 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 17:07:18 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->y_axis)
	{
		j = 0;
		while (j < game->x_axis)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i][j + 1]))
			{
				if (game->map[i][j + 1] == 'C')
					colect_d(game, game->map[i][j + 1], i, j);
				aux = game->map[i][j + 1];
				game->map[i][j + 1] = game->map[i][j];
				game->map[i][j] = aux;
				j++;
			}
			j++;
		}
		i++;
	}
}

void	move_a(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->y_axis)
	{
		j = 0;
		while (j < game->x_axis)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i][j - 1]))
			{
				if (game->map[i][j - 1] == 'C')
					colect_a(game, game->map[i][j - 1], i, j);
				aux = game->map[i][j - 1];
				game->map[i][j - 1] = game->map[i][j];
				game->map[i][j] = aux;
				j++;
			}
			j++;
		}
		i++;
	}
}

void	move_s(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->y_axis)
	{
		j = 0;
		while (j < game->x_axis)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i + 1][j]))
			{
				if (game->map[i + 1][j] == 'C')
					colect_s(game, game->map[i + 1][j], i, j);
				aux = game->map[i + 1][j];
				game->map[i + 1][j] = game->map[i][j];
				game->map[i][j] = aux;
				i++;
			}
			j++;
		}
		i++;
	}
}

void	move_w(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->y_axis)
	{
		j = 0;
		while (j < game->x_axis)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i - 1][j]))
			{
				if (game->map[i - 1][j] == 'C')
					colect_w(game, game->map[i - 1][j], i, j);
				aux = game->map[i - 1][j];
				game->map[i - 1][j] = game->map[i][j];
				game->map[i][j] = aux;
				i++;
			}
			j++;
		}
		i++;
	}
}

void	check_heart(t_data *game)
{
	if (game->key == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->exit);
		game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
				"image/heart_full.xpm", &game->width, &game->height);
	}
}
