/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:33:52 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 21:45:08 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		file_in;
	int		file_out;
	t_data	data;

	argc_validator(argc);
	file_in = open(argv[1], O_RDONLY);
	file_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	open_file_validator(file_in, file_out, argv[1], argv[argc - 1]);
	// printf("argv[2]: %s\n", argv[2]);
	data.first_cmd = handle_command(argv[2]);
	// printf("\nRETORNO CMD1: %s\n", data.first_cmd);
	data.last_cmd = handle_command(argv[3]);
	// printf("\nRETORNO CMD2: %s\n", data.last_cmd);
	data.argv = argv;
	data.envp = envp;
	data.file_in = file_in;
	data.file_out = file_out;
	pipering(data);
	return (0);
}
