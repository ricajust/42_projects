/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:58:19 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 08:30:47 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	detach_command_and_flags(char *argument_v, t_data *data)
{
	int		i;

	data->command_and_flags = ft_split(argument_v, ' ');
	i = 0;
	while (data->command_and_flags[i])
	{
		printf("command %d: %s\n", i, data->command_and_flags[i]);
		i++;
	}
}

char	*find_command(char *argument_v, char **envp, t_data *data)
{
	int		i;
	char	*env_path;
	char	**paths;
	char	*path_and_command;

	detach_command_and_flags(argument_v, data);
	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
		{
			env_path = ft_substr(env_path, 0, ft_strlen(env_path));
			break ;
		}
		i++;
	}
	printf("Environment path: %s\n", env_path);
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		// printf("Paths: %s\n", paths[i]);
		paths[i] = ft_strjoin(paths[i], "/");
		// printf("Paths: %s\n", paths[i]);
		path_and_command = ft_strjoin(paths[i], data->command_and_flags[0]);
		// printf("Path and command: %s\n", path_and_command);
		if (access(path_and_command, F_OK | X_OK) == 0)
		{
			return (path_and_command);
		}
		i++;
		free(path_and_command);
	}
	return (0);
}

void	pipering(t_data data, int file_1, int file_2, char **argv, char **envp)
{
	int		file_descriptor[2];
	pid_t	process_id;
	char	*command;

	pipe_validator(pipe(file_descriptor));
	process_id = fork();
	fork_validator(process_id);
	if (process_id == 0)
	{
		dup2(file_1, STDIN_FILENO);
		dup2(file_descriptor[1], STDOUT_FILENO);
		close(file_descriptor[0]);
		command = find_command(argv[2], envp, &data);
		execve(command, data.command_and_flags, envp);
	}
	else
	{
		dup2(file_2, STDOUT_FILENO);
		waitpid(-1, NULL, WNOHANG);
		dup2(file_descriptor[0], STDIN_FILENO);
		close(file_descriptor[1]);
		command = find_command(argv[3], envp, &data);
		execve(command, data.command_and_flags, envp);
	}
	close(file_1);
	close(file_2);
}
