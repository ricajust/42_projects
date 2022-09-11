/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:58:19 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 14:54:54 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

/**
 * @brief Find "PATH=" in env variable
 * 
 * @param envp char ** bi-dimensional array with environment variable
 * @return char* string with "PATH="
 */
char	*find_path_in_env(char **envp)
{
	int		i;
	char	*env_path;

	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
		{
			env_path = ft_substr(env_path, 0, ft_strlen(env_path));
			return (env_path);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Detach flags from command, find PATH in environment variable, 
 * separetes directories and add "/" in end, check if path with command is in 
 * directory and if executable
 * 
 * @param command_with_flag 
 * @param envp 
 * @param data 
 * @return char* 
 */
char	*find_command(char *command_with_flag, t_data *data)
{
	int		i;
	char	*env_path;
	char	**paths;
	char	*path_and_command;

	data->command_and_flags = ft_split(command_with_flag, ' ');
	env_path = find_path_in_env(data->envp);
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		path_and_command = ft_strjoin(paths[i], data->command_and_flags[0]);
		if (access(path_and_command, F_OK | X_OK) == 0)
			return (path_and_command);
		i++;
		free(path_and_command);
	}
	return (0);
}

/**
 * @brief prepares and executes the first command with its flag and sends the 
 * output over the pipe to the input of the parent process
 * 
 * 
 * @param file_descriptor int vector with pipe file descriptors
 * @param data struct with program data
 */
void	child_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(data->file_1, STDIN_FILENO);
	dup2(file_descriptor[1], STDOUT_FILENO);
	close(file_descriptor[0]);
	command = find_command(data->argv[2], data);
	execve(command, data->command_and_flags, data->envp);
}

/**
 * @brief catch data from child process and execute the seccond command, the 
 * output will be in outfile
 * 
 * @param file_descriptor int vector with pipe file descriptors
 * @param data struct with program data
 */
void	parent_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(data->file_2, STDOUT_FILENO);
	dup2(file_descriptor[0], STDIN_FILENO);
	close(file_descriptor[1]);
	command = find_command(data->argv[3], data);
	execve(command, data->command_and_flags, data->envp);
}

/**
 * @brief orchestration and execution from both commands with yours flags
 * 
 * @param data struct with program data
 */
void	pipering(t_data data)
{
	int		file_descriptor[2];
	pid_t	process_id;

	pipe_validator(pipe(file_descriptor));
	process_id = fork();
	fork_validator(process_id);
	if (process_id == 0)
	{
		child_process(file_descriptor, &data);
	}
	else
	{
		waitpid(-1, NULL, WNOHANG);
		parent_process(file_descriptor, &data);
	}
	close(data.file_1);
	close(data.file_2);
}
