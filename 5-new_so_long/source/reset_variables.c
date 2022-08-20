/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 07:45:00 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 20:44:46 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_variables(t_data *game)
{
	game->row = 0;
	game->column = 0;
	game->total_collectible = 0;
	game->total_player = 0;
	game->total_exit = 0;
	game->moviment = 0;
}
