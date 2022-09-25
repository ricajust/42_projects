/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:24:50 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 21:30:28 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_error(t_data *data, char *command)
{
	char	*error;

	error = ft_strjoin_f(data->command_and_flags[0], " : command not found\n");
	ft_putstr_fd(error, 2);
	free_matrix(data->command_and_flags);
	if (command)
		free(command);
	free(error);
	return (127);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i] != NULL)
			free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_all(char *env_path, char **paths)
{
	free(env_path);
	free_matrix(paths);
}
