/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:58:19 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 14:48:32 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		wait(NULL);
		parent_process(file_descriptor, &data);
	}
	close(data.file_in);
	close(data.file_out);
}
