/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:58:19 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/08 20:53:58 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	find_command(char *argument_v, char **envp)
{
	int		i;
	char	**commands;
	char	*command_path;

	commands = ft_split(argument_v, ' ');
	i = 0;
	while (commands[i])
	{
		printf("command %d: %s\n", i, commands[i]);
		i++;
	}
	i = 0;
	while (envp[i])
	{
		command_path = ft_strnstr(envp[i], "PATH=", 5);
		if (command_path)
			printf("path: %s\n", command_path);
		i++;
	}
}

void	pipering(int file_1, int file_2, char **argv, char **envp)
{
	int		file_descriptor[2];
	int		pipe_return;
	pid_t	process_id;

	pipe_return = pipe(file_descriptor);
	pipe_validator(pipe_return);
	process_id = fork();
	if (process_id == 0)
	{
		dup2(file_1, STDIN_FILENO);
		// dup2(file_descriptor[1], STDOUT_FILENO);
		close(file_descriptor[0]);
		find_command(argv[2], envp);
		execlp("ls", "ls", NULL);
	}
	else
	{
		dup2(file_2, STDOUT_FILENO);
		// waitpid(NULL);
		waitpid(-1, NULL, WNOHANG);
		dup2(file_descriptor[0], STDIN_FILENO);
		close(file_descriptor[1]);
		execlp("cat", "cat", NULL);
		// execute_command(argv[3], envp);
	}
	close(file_1);
	close(file_2);
}
