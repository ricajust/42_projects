/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:35:27 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 17:08:07 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collectible(t_data *game)
{
	int		fd;
	char	*box;
	int		i;

	game->key = 0;
	fd = open (game->file_path, O_RDONLY);
	box = ft_get_next_line(fd);
	while (box)
	{
		i = 0;
		while (box[i] != '\0')
		{
			if (box[i] == 'C')
				game->key = game->key + 1;
			i++;
		}
		free (box);
		box = ft_get_next_line(fd);
	}
	close (fd);
}

void	colect_w(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i - 1][j] = '0';
		game->key = game->key - 1;
		check_heart(game);
	}
}

void	colect_s(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i + 1][j] = '0';
		game->key = game->key - 1;
		check_heart(game);
	}
}

void	colect_a(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i][j - 1] = '0';
		game->key = game->key - 1;
		check_heart(game);
	}
}

void	colect_d(t_data *game, char c, int i, int j)
{
	if (c == 'C')
	{
		game->map[i][j + 1] = '0';
		game->key = game->key - 1;
		check_heart(game);
	}
}
