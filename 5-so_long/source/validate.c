/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:37:15 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 14:37:16 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	val(t_data *game, char c)
{
	if (c == '1')
		return (0);
	else if (c == 'E')
	{
		if (game->key == 0)
		{
			game->moviment++;
			printf("Moviments: %d\n", game->moviment);
			printf("\nYou win\n");
			closee(game);
		}
		else
			return (0);
	}
	else
	{
		game->moviment = game->moviment + 1;
		return (1);
	}
	return (0);
}
