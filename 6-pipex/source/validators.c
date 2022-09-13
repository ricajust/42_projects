/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:57:40 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/12 19:50:20 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argc_validator(int argc)
{
	if (argc < 5)
	{
		ft_printf("pipex: Insufficient arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 5)
	{
		ft_printf("pipex: Too much arguments\n!");
		exit(EXIT_FAILURE);
	}
}

void	open_file_validator(int fd_1, int fd_2, char *file_name)
{
	if (fd_1 < 0)
	{
		close(fd_1);
		close(fd_2);
		ft_printf("pipex: %s: No such file or directory\n", file_name);
		exit(EXIT_FAILURE);
	}
}

void	pipe_validator(int pipe_return)
{
	if (pipe_return == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	fork_validator(pid_t process_id)
{
	if (process_id < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
