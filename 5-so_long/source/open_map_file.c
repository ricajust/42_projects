/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:38:32 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 21:36:56 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map_file(t_data *game)
{
	int		file_descriptor;
	char	*map_line;
	char	*map_raw;

	map_raw = ft_strdup("");
	file_descriptor = open(game->file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		ft_printf("Error\nPlease, check input file. Error in file descriptor\n");
		free(map_raw);
		close(file_descriptor);
		exit(1);
	}
	map_line = ft_get_next_line(file_descriptor);
	while (map_line)
	{
		map_raw = ft_strjoin(map_raw, map_line);
		free(map_line);
		map_line = ft_get_next_line(file_descriptor);
	}
	game->map = ft_split(map_raw, '\n');
	free(map_raw);
	close(file_descriptor);
}
