/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:42:22 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/19 21:20:06 by rda-silv         ###   ########.fr       */
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
	int		row;
	int		column;
	int		total_collectible;
	int		total_player;
	int		total_exit;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
	int		i;
	int		j;
	int		moviment;
	int		width;
	int		height;
}	t_data;

/**
 * @brief This function check input arguments and validate your quantity and
 * file name. He must end with ".ber" extension
 * 
 * @param argc quantity of arguments, must be 2, one binary and other file name
 * @param filename the file name
 * @param game game struct, we are storage the information in pointer file_name
 */
void	input_validator(int argc, char *file_name, t_data *game);

/**
 * @brief Reset all variables
 * 
 * @param game game struct
 */
void	reset_variables(t_data *game);

/**
 * @brief Open .ber file with contains map info and put in struct
 * 
 * @param game game struct, were storage bidimensional matrix with map 
 * information
 */
void	open_map_file(t_data *game);

/**
 * @brief Just a search algorithm
 * 
 * @param game game struct with map information
 * 
 */
void	tracker(t_data *game);

/*********************************************/
/*************** HANDLE CHECKS ***************/
/*********************************************/
/**
 * @brief Check map shape and handle with errors, comparing the first line with
 * next until matrix end.
 * 
 * @param game game struct
 * @param j length of first line
 * @param length lenght of seccond line
 */
void	check_shape(t_data *game, int j, int length);

/**
 * @brief Check if map pointer is valid and handle with error
 * 
 * @param game game struct
 */
void	check_map_pointer(t_data *game);

/**
 * @brief Check all items in line, counting 'C', 'P' and 'E'
 * 
 * @param game 
 * @param i 
 */
void	check_items(t_data *game, int i);

/**
 * @brief Check the amount of 'C', 'P' and 'E' 
 * 
 * @param game game struct
 */
void	check_items_size(t_data *game);

/**
 * @brief Check if map is surrounded by 1's, first check in vertical edges then
 * check horizontal edges
 * 
 * @param game game struct
 */
void	check_walls(t_data *game);

/*********************************************/
/************* EXCEPITION MANAGER ************/
/*********************************************/
/**
 * @brief show error mensage when pointer is invalid
 * 
 * @param game 
 */
void	error_pointer(t_data *game);

/**
 * @brief show error mensages when find invalid items in map
 * 
 * @param game game struct
 * @param c wrong character
 */
void	error_items(t_data *game, char c);

/**
 * @brief show error mensages when map shape is invalid
 * 
 * @param game game struct
 */
void	error_shape(t_data *game);

/**
 * @brief Show error mesages when number os player or exit isn't 1
 * 
 * @param game game struct
 * @param flag player or exit identifier
 */
void	error_size_items(t_data *game, char flag);

/**
 * @brief Show error mesages when vertical or horizontal map edge isn't '1'
 * 
 * @param game game struct
 */
void	error_walls(t_data *game, char flag);

/*********************************************/
/*************** GAME MANAGER ****************/
/*********************************************/
/**
 * @brief Create a window with mlx library
 * 
 * @param game game struct
 */
void	create_window(t_data *game);

/**
 * @brief This function re-render the contents when window is overlaid
 * 
 * @param game game struct
 * @return int value
 */
int		ft_expose(t_data *game);

/**
 * @brief Put xpm images in corresponding variables
 * 
 * @param game game struct
 */
void	put_sprites(t_data *game);

/**
 * @brief Put image in window in corresponding character in text map
 * 
 * @param game game struct
 * @param tile character in text map
 */
void	put_image(t_data *game, char tile);

/**
 * @brief Render text map in window, replace characters by corresponding xpm 
 * images
 * 
 * @param game game struct
 */
void	render(t_data *game);

/**
 * @brief 
 * 
 * @param game 
 */
void	free_matrix(t_data *game);

/**
 * @brief free all variables allocated memory heap with free_matrix() function 
 * and destroy display and window
 * 
 * @param game game struct
 */
void	clear_allocated_vars(t_data *game);

/**
 * @brief Close all game, calls clear_allocated_vars() and free_matrix() and 
 * destroy all images
 * 
 */
int		close_game(t_data *game);

/*********************************************/
/************* GAMEPLAY MANAGER **************/
/*********************************************/
/**
 * @brief Interface between keyboard and character in window, identify key and 
 * call corresponding function
 * 
 * @param key pressed key in keyboard
 * @param game game struct
 */
int		key_release(int key, t_data *game);

/**
 * @brief Replace actual image by right xpm and call mode_d();
 * 
 * @param game game sctruct
 */
void	walk_right(t_data *game);

/**
 * @brief 
 * 
 * @param game 
 */
void	move_d(t_data *game);

/**
 * @brief Replace actual image by left xpm and call mode_a();
 * 
 * @param game game sctruct
 */
void	walk_left(t_data *game);

void	move_a(t_data *game);

/**
 * @brief Replace actual image by down xpm and call mode_s();
 * 
 * @param game game sctruct
 */
void	walk_down(t_data *game);

void	move_s(t_data *game);

/**
 * @brief Replace actual image by up xpm and call mode_w();
 * 
 * @param game game sctruct
 */
void	walk_up(t_data *game);

void	move_w(t_data *game);

int		val(t_data *game, char c);

void	colect_w(t_data *game, char c, int i, int j);

void	colect_s(t_data *game, char c, int i, int j);

void	colect_a(t_data *game, char c, int i, int j);

void	colect_d(t_data *game, char c, int i, int j);

void	check_chest(t_data *game);

#endif