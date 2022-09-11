/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:51 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 16:41:39 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int*file_descriptor, t_data *data)
{
	char	*command;
	int		i;
	
	dup2(data->file_1, STDIN_FILENO);
	dup2(file_descriptor[1], STDOUT_FILENO);
	close(file_descriptor[0]);
	command = find_command(data->argv[2], data);

	execve(command, data->command_and_flags, data->envp);
	perror("pipex");
	i = 0;
	free(command);
	while (data->command_and_flags[i])
	{
		ft_printf("%d - %s\n", i, data->command_and_flags[i]);
		free(data->command_and_flags[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	parent_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(data->file_2, STDOUT_FILENO);
	dup2(file_descriptor[0], STDIN_FILENO);
	close(file_descriptor[1]);
	command = find_command(data->argv[3], data);
	execve(command, data->command_and_flags, data->envp);
	perror("pipex");
	free(command);
	exit(EXIT_FAILURE);
}
