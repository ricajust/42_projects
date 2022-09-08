/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:57:36 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/08 08:08:31 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include "./../library/libft/libft.h"

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
 * @param name_file file name (argv)
 */
void	open_file_validator(int fd_1, int fd_2, char *name_file);

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
 */
void	fork_validator(pid_t process_id);

/**
 * @brief 
 * 
 * @param file_1 
 * @param file_2 
 * @param argv 
 * @param envp 
 */
void	pipering(int file_1, int file_2, char **argv, char **envp);

/**
 * @brief 
 * 
 * @param command 
 * @param envp 
 */
void	execute_command(char *command, char **envp);

#endif