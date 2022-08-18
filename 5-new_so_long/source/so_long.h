/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:42:22 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/17 20:25:50 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "./../library/libft/libft.h"
# include "./../library/minilibx/mlx.h"

typedef struct s_data
{
	char	**map;
	char	*file_name;
}	t_data;
/**
 * @brief Get the map object
 * 
 * @param game 
 */

/**
 * @brief This function check input arguments and validate your quantity and
 * file name. He must end with ".ber" extension
 * 
 * @param argc quantity of arguments, must be 2, one binary and other file name
 * @param filename the file name
 * @param game game struct, we are storage the information in pointer file_name
 */
void	input_validator(int argc, char *file_name, t_data *game);

void	get_map(t_data *game);
#endif