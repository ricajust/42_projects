/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:51:00 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/16 00:26:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include "mlx.h"
# include "./../library/libft/libft.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*tree;
	void	*player;
	void	*exit;
	void	*collectible;
	char	**map;
	char	*file_path;
	int		file_descriptor;
	int		x_axis;
	int		y_axis;
	int		width;
	int		height;
	int		key;
	int		amount_player;
	int		amount_collectible;
	int		amount_exit;
	int		moviment;
	int		i;
	int		j;
}	t_data;

// main function

int		key_release(int key, t_data *itens);
void	render(t_data *itens);
void	get_map(t_data *itens);

//iniatilize map

void	*y_axis_length(t_data *itens);
void	put_sprites(t_data *itens);
void	x_axis_length(t_data *itens);

// colect

void	check_collectible(t_data *itens);
void	colect_s(t_data *itens, char c, int n1, int n2);
void	colect_w(t_data *itens, char c, int n1, int n2);
void	colect_a(t_data *itens, char c, int n1, int n2);
void	colect_d(t_data *itens, char c, int n1, int n2);

// check map

void	check_map(t_data *itens);
void	check_map_error(t_data *game);
void	reset_all(t_data *game);
void	check_rectangle(t_data *itens);
void	check_wall(t_data *itens);
void	check_elements(t_data *itens);
int		define(t_data *itens);

// validate

int		closee(t_data *itens);
int		clear_memory(t_data *itens);
void	free_matrix(t_data *itens);
int		val(t_data *itens, char c);
void	free_matrix(t_data *game);
void	input_validation(int argc, char *file_path, t_data *game);

// Moviment

void	walk_right(t_data *itens);
void	walk_left(t_data *itens);
void	walk_down(t_data *itens);
void	walk_up(t_data *itens);

// Moviment direction

void	move_d(t_data *itens);
void	move_a(t_data *itens);
void	move_s(t_data *itens);
void	move_w(t_data *itens);
void	check_heart(t_data *game);
#endif
