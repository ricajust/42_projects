/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:57:36 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 16:30:20 by rda-silv         ###   ########.fr       */
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
 * @param argc (int) value must be 5:
 * 1 to binary | 2 to file 1 | 3 to command 1 | 4 to file 2 | 5 to command 2
 */
void	argc_validator(int argc);

/**
 * @brief open file validator, check if files descriptors is < 0, what if, show
 * error message and close program
 * 
 * @param fd_1 (file) file descriptor input file
 * @param fd_2 (file) file descriptor output file
 */
void	open_file_validator(int fd_1, int fd_2);

/**
 * @brief pipe create process validator
 * 
 * @param pipe_return (int) value returns pipe creation, if value is -1 then pipe
 * creation failure * 
 */
void	pipe_validator(int pipe_return);

/**
 * @brief fork create process validator
 * 
 * @param process_id (int) value returns fork creation, if value is -1 then 
 * fork creation failure
 */
void	fork_validator(pid_t process_id);

/**
 * @brief Simple error handling show message and free all possible memory 
 * allocation
 * 
 * @param command (char * array) with command
 * @param data (struct) with program data
 */
void	error_handling(char *command, t_data *data);

/**
 * @brief Make all orchestration and execution from both commands with yours 
 * flags. Create pipe, create fork and execute the first command in the child 
 * process and the second command (with result of the first command) in the 
 * parent process, where the program output is displayed in the outfile file
 * 
 * @param data (struct) with program data
 */
void	pipering(t_data data);

/**
 * @brief Find "PATH=" in env variable
 * 
 * @param envp (char ** bi-dimensional arra)y with environment variable
 * 
 * @return (char * array) with string "PATH=", or 0 if not find PATH in env
 */
char	*find_path_in_env(char **envp);

/**
 * @brief Detach flags from command, find PATH in environment variable, 
 * separetes directories and add "/" in end, check if path with command is in 
 * directory and if executable
 * 
 * @param command_with_flag (char * array) with separate flags from your 
 * command
 * @param envp (char ** bi-dimensional array) with environment variable
 * @param data (struct) with program data
 * 
 * @return (char * array) with path and command ex: "/usr/bin/ls", or 0 if not
 * find command ou command don't executed
 */
char	*find_command(char *command_with_flag, t_data *data);

/**
 * @brief prepares and executes the first command with its flag and sends the 
 * output over the pipe to the input of the parent process
 * 
 * 
 * @param file_descriptor int vector with pipe file descriptors
 * @param data struct with program data
 */
void	child_process(int*file_descriptor, t_data *data);

/**
 * @brief catch data from child process and execute the seccond command, the 
 * output will be in outfile
 * 
 * @param file_descriptor int vector with pipe file descriptors
 * @param data struct with program data
 */
void	parent_process(int*file_descriptor, t_data *data);

/**
 * @brief 
 * 
 * @param command 
 * @param envp 
 */
void	execute_command(char *command, char **envp);

#endif