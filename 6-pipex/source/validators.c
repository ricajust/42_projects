/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:57:40 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/21 19:42:45 by rda-silv         ###   ########.fr       */
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

void	show_error(char *filein, char *str_phrase)
{
	char	*error;

	error = NULL;
	error = ft_strjoin_f(filein, str_phrase);
	ft_putstr_fd(error, 2);
	ft_strdel(&error);
}

void	open_file_validator(int fd_1, int fd_2, char *filein, char *fileout)
{
	if (fd_1 < 0)
	{
		if (access(filein, F_OK) != 0)
			show_error(filein, " : No such file or directory\n");
		else
			if (access(filein, R_OK) != 0)
				show_error(filein, " : Permission denied\n");
		close(fd_1);
		exit(EXIT_FAILURE);
	}
	else if (fd_2 < 0)
	{
		close(fd_2);
		show_error(fileout, " : Permission denied\n");
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
