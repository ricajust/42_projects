/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:10:07 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 20:57:21 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i][j + 1]))
			{
				if (game->map[i][j + 1] == 'C')
					colect_d(game, game->map[i][j + 1], i, j);
				aux = game->map[i][j + 1];
				game->map[i][j + 1] = game->map[i][j];
				game->map[i][j] = aux;
				j++;
			}
			j++;
		}
		i++;
	}
}

void	move_a(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i][j - 1]))
			{
				if (game->map[i][j - 1] == 'C')
					colect_a(game, game->map[i][j - 1], i, j);
				aux = game->map[i][j - 1];
				game->map[i][j - 1] = game->map[i][j];
				game->map[i][j] = aux;
				j++;
			}
			j++;
		}
		i++;
	}
}

void	move_s(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i + 1][j]))
			{
				if (game->map[i + 1][j] == 'C')
					colect_s(game, game->map[i + 1][j], i, j);
				aux = game->map[i + 1][j];
				game->map[i + 1][j] = game->map[i][j];
				game->map[i][j] = aux;
				i++;
			}
			j++;
		}
		i++;
	}
}

void	move_w(t_data *game)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->column)
		{
			if (game->map[i][j] == 'P' && val(game, game->map[i - 1][j]))
			{
				if (game->map[i - 1][j] == 'C')
					colect_w(game, game->map[i - 1][j], i, j);
				aux = game->map[i - 1][j];
				game->map[i - 1][j] = game->map[i][j];
				game->map[i][j] = aux;
				i++;
			}
			j++;
		}
		i++;
	}
}

int	val(t_data *game, char c)
{
	if (c == '1')
		return (0);
	else if (c == 'E')
	{
		if (game->total_collectible == 0)
		{
			game->moviment++;
			ft_printf("Moviments: %d\n", game->moviment);
			ft_printf("\nYou win\n");
			close_game(game);
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
