/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_poc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:41:50 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/05 21:28:19 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_poc.h"

int	main(int argc, char **argv, char **envp)
{
	char *commands_and_arguments[3] = {argv[1], argv[2], NULL};
	char *command_path;

	argc_validator(argc);
	command_path = get_command_path(argv[1], envp);
	if (!command_path)
	{
		perror(command_path);
		return (-1);
	}
	execve(command_path, commands_and_arguments, envp);
	ft_printf("Vitory!!!");
	return (0);
}
