/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:57:40 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 08:17:13 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argc_validator(int argc)
{
	if (argc < 5)
	{
		ft_printf("Error\n%d - is insufficient arguments, try again\n", argc);
		exit(-1);
	}
	else if (argc > 5)
	{
		ft_printf("Error\n%d - is too much arguments, try again\n!", argc);
		exit(-1);
	}
}

void	open_file_validator(int fd_1, int fd_2, char *name_file)
{
	if (fd_1 < 0)
	{
		close(fd_1);
		close(fd_2);
		ft_printf("pipex: %s: No such file or directory\n", name_file);
	}
}

void	pipe_validator(int pipe_return)
{
	if (pipe_return == -1)
	{
		perror("pipe error...");
		exit(-1);
	}
}

void	fork_validator(pid_t process_id)
{
	if (process_id < 0)
	{
		ft_printf("Error\nFail to create fork process, please try again!\n");
		exit(-1);
	}
}
