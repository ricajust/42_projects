/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:51 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 21:31:37 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_file_descriptor(int file_descriptor, t_data *data)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(file_descriptor);
	close(data->file_in);
	close(data->file_out);
}

void	child_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(data->file_in, STDIN_FILENO);
	dup2(file_descriptor[1], STDOUT_FILENO);
	close(file_descriptor[0]);
	command = find_command(data->first_cmd, data);
	// printf("COMANDO LOCALIZADO: %s\n", command);
	if (!command)
	{
		close_all_file_descriptor(file_descriptor[1], data);
		exit(handle_error(data, command));
	}
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
	// dup2(data->file_out, STDOUT_FILENO);
	close(file_descriptor[1]);
	command = find_command(data->last_cmd, data);
	if (!command)
	{
		close_all_file_descriptor(file_descriptor[0], data);
		exit(handle_error(data, command));
	}
	execve(command, data->command_and_flags, data->envp);
	free_matrix(data->command_and_flags);
	free(command);
	exit(EXIT_FAILURE);
}
