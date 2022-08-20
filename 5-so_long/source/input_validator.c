/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:24:17 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/17 20:26:10 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_validator(int argc, char *file_name, t_data *game)
{
	int		name_length;
	char	*result;

	if (argc != 2)
	{
		ft_printf("Error:\nPlease, insert just one map file name\n");
		exit(1);
	}
	name_length = ft_strlen(file_name);
	result = ft_strnstr(file_name, ".ber", name_length);
	if (result == NULL)
	{
		ft_printf("Error:\nPlease, insert a valid map\n");
		exit(1);
	}
	game->file_name = file_name;
}
