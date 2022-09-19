/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:51 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/19 08:16:56 by rda-silv         ###   ########.fr       */
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
	if (!command)
		exit(handle_error(data, command));
	execve(command, data->command_and_flags, data->envp);
	perror("execve");
	free_matrix(data->command_and_flags);
	free(command);
	exit(EXIT_FAILURE);
}

void	parent_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(file_descriptor[0], STDIN_FILENO);
	// dup2(data->file_2, STDOUT_FILENO);
	close(file_descriptor[1]);
	command = find_command(data->argv[3], data);
	if (!command)
		exit(handle_error(data, command));
	execve(command, data->command_and_flags, data->envp);
	free_matrix(data->command_and_flags);
	free(command);
	exit(EXIT_FAILURE);
}
