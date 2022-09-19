/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:24:50 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/19 08:18:24 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_error(t_data *data, char *command)
{
	ft_printf("%s: command not found\n", data->command_and_flags[0]);
	free_matrix(data->command_and_flags);
	free(command);
	return (127);
}
