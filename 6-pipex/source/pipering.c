/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:58:19 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 16:34:53 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	pipering(t_data data)
{
	int		file_descriptor[2];
	pid_t	process_id;

	pipe_validator(pipe(file_descriptor));
	process_id = fork();
	fork_validator(process_id);
	if (process_id == 0)
		child_process(file_descriptor, &data);
	else
	{
		waitpid(-1, NULL, WNOHANG);
		parent_process(file_descriptor, &data);
	}
	close(data.file_1);
	close(data.file_2);
}
