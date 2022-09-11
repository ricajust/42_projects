/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:57:36 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 14:41:20 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "./../library/libft/libft.h"

typedef struct s_data
{
	int		file_1;
	int		file_2;
	char	**argv;
	char	**envp;
	char	**command_and_flags;
}	t_data;

/**
 * @brief arguments validator
 * 
 * @param argc int value must be 5:
 * 1 to binary | 2 to file 1 | 3 to command 1 | 4 to file 2 | 5 to command 2
 */
void	argc_validator(int argc);

/**
 * @brief open file validator, check if files descriptors is < 0, what if, show
 * error message and close program
 * 
 * @param fd_1 file descriptor input file
 * @param fd_2 file descriptor output file
 * @param name_file char * with file name (input in argv)
 */
void	open_file_validator(int fd_1, int fd_2, char *name_file, t_data *data);

/**
 * @brief pipe create process validator
 * 
 * @param pipe_return int value returns pipe creation, if value is -1 then pipe
 * creation failure * 
 */
void	pipe_validator(int pipe_return);

/**
 * @brief fork create process validator
 * 
 * @param process_id int value returns fork creation, if value is -1 then fork 
 * creation failure
 */
void	fork_validator(pid_t process_id);

/**
 * @brief create pipe, create fork and execute the first command in the child 
 * process and the second command (with result of the first command) in the 
 * parent process, where the program output is displayed in the outfile file
 * 
 * 
 * @param file_1 the infile file
 * @param file_2 the outfile file
 * @param argv char ** bi-dimensional array with input commands and your flags
 * @param envp char ** bi-dimensional array with environment variable
 */
void	pipering(t_data data);

/**
 * @brief 
 * 
 * @param command 
 * @param envp 
 */
void	execute_command(char *command, char **envp);

#endif