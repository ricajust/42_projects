/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:06:47 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/25 10:18:13 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*handle_command(char *raw_command, char *final_command)
{
	char	*command;
	char	**command_without_single_quote;

	command = raw_command;
	if (command[0] == 39 && command[ft_strlen(command) - 1] == 39)
	{
		command_without_single_quote = ft_split(command, 39);
		command = ft_strdup(command_without_single_quote[0]);
		free_matrix(command_without_single_quote);
	}
	final_command = ft_strjoin(command, " ");
	command = NULL;
	return (final_command);
}

char	*handle_flag(char *raw_flag, char *final_command)
{
	char	*flag;
	char	**flag_without_single_quote;

	flag = raw_flag;
	if (flag && flag[0] == 39 && flag[ft_strlen(flag) - 1] == 39)
	{
		flag_without_single_quote = ft_split(flag, 39);
		flag = ft_strdup(flag_without_single_quote[0]);
		free_matrix(flag_without_single_quote);
	}
	final_command = ft_strjoin(final_command, flag);
	flag = NULL;
	return (final_command);
}

char	*handle_command_and_flag(char *cmd)
{
	char	**command_and_flag;
	char	*final_command;
	int		i;

	if (cmd[0] == 39 && cmd[ft_strlen(cmd) - 1] == 39)
		return (cmd);
	command_and_flag = ft_split(cmd, ' ');
	i = 0;
	while (command_and_flag[i])
	{
		if (i == 0)
			final_command = handle_command(command_and_flag[i], final_command);
		else
			final_command = handle_flag(command_and_flag[i], final_command);
		i++;
	}
	free(command_and_flag);
	return (final_command);
}
