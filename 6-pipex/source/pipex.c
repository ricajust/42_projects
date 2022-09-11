/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:33:52 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 08:11:40 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		file_1;
	int		file_2;
	t_data	data;

	argc_validator(argc);
	file_1 = open(argv[1], O_RDONLY);
	file_2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	open_file_validator(file_1, file_2, argv[1]);
	pipering(data, file_1, file_2, argv, envp);
	return (0);
}
