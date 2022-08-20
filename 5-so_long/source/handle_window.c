/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:06:48 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/20 12:52:29 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_data *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->column * 32),
			(game->row * 32), "So Long Game");
}

int	ft_expose(t_data *game)
{
	render(game);
	return (1);
}
