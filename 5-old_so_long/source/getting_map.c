/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:36:37 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/17 21:59:39 by rda-silv         ###   ########.fr       */
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
			"image/ground.xpm", &x, &y);
	game->tree = mlx_xpm_file_to_image(game->mlx_ptr,
			"image/tree.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"image/down.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"image/heart_empty.xpm", &x, &y);
	game->collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"image/collectible.xpm", &x, &y);
}

static void	put_image(t_data *game, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tree,
			(50 * game->j), (50 * game->i));
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
			(50 * game->j), (50 * game->i));
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit,
			(50 * game->j), (50 * game->i));
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible,
			(50 * game->j), (50 * game->i));
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor,
			(50 * game->j), (50 * game->i));
	else if (tile == 'F')
	{
		printf("Error\nVerify the elements in the map.\n");
		closee(game);
		exit(1);
	}
}

void	render(t_data *game)
{
	game->i = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (game->i < game->y_axis)
	{
		game->j = 0;
		while (game->j < game->x_axis)
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

void	get_map(t_data *game)
{
	int		fd;
	char	*map_line;
	char	*raw_map;

	fd = open(game->file_path, O_RDONLY);
	raw_map = ft_strdup("");
	map_line = ft_get_next_line(fd);
	while (map_line)
	{
		raw_map = ft_strjoin(raw_map, map_line);
		free(map_line);
		map_line = ft_get_next_line(fd);
	}
	game->map = ft_split(raw_map, '\n');
	free(raw_map);
	close(fd);
}
