/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:38:32 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/17 21:11:19 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_data *game)
{
	int		file_descriptor;
	char	*map_raw;
	char	*line;

	map_raw = NULL;
	file_descriptor = open(game->file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		ft_printf("Error\nPlease, check input file. Error in file descriptor");
		exit(1);
	}
	line = ft_get_next_line(file_descriptor);
	ft_printf("\nFirst line: %s\n", line);
	while (line)
	{
		ft_strjoin(map_raw, line);
		free(line);
		ft_printf("\nnext line: %s\n", map_raw);
	}
	free(map_raw);
	map_raw = NULL;
}
