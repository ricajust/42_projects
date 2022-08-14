/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:36:46 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 14:36:47 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int key, t_data *game)
{
	if (key == 0xff1b)
		closee(game);
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
	printf("Moviments: %d\n", game->moviment);
	return (1);
}
