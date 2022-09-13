/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:51 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/12 21:16:35 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(data->file_1, STDIN_FILENO);
	dup2(file_descriptor[1], STDOUT_FILENO);
	close(file_descriptor[0]);
	command = find_command(data->argv[2], data);
	execve(command, data->command_and_flags, data->envp);
	perror("pipex");
	free_matrix(data->command_and_flags);
	free(command);
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
	free_matrix(data->command_and_flags);
	free(command);
	perror("pipex");
	exit(EXIT_FAILURE);
}
