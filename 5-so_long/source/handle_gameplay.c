/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_gameplay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:57:01 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 20:55:56 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int key, t_data *game)
{
	if (key == 0xff1b)
		close_game(game);
	if (key == 'd')
	{
		walk_right(game);
		render(game);
	}
	if (key == 'a')
	{
		walk_left(game);
		render(game);
	}
	if (key == 's')
	{
		walk_down(game);
		render(game);
	}
	if (key == 'w')
	{
		walk_up(game);
		render(game);
	}
	ft_printf("Moviments: %d\n", game->moviment);
	return (1);
}
