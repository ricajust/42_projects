/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:06:47 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/29 08:24:43 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	replace_space(char *command, int *indice)
{
	(*indice)++;
	while (command[*indice] && command[*indice] != 39)
	{
		if (command[*indice] == 32)
			command[*indice] = '\a';
		(*indice)++;
	}
	if (command[*indice] == '\0')
		return (1);
	return (0);
}

void	return_space(char **command)
{
	int	i;
	int	j;

	i = 0;
	while (command[i])
	{
		j = 0;
		while (command[i][j])
		{
			if (command[i][j] == '\a')
				command[i][j] = 32;
			(j)++;
		}
		i++;
	}
}

char	**replace_and_split(char *command, int flag)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == 39 && flag == 0)
			flag = replace_space(command, &i);
		i++;
	}
	return (ft_split(command, 32));
}

char	**handle_command_and_flag(char *command)
{
	int		flag;
	int		i;
	char	**cmds;
	char	*temp;

	flag = 0;
	cmds = replace_and_split(command, flag);
	if (flag == 1)
		return (cmds);
	i = 0;
	while (cmds[i])
	{
		temp = ft_strtrim(cmds[i], "'");
		free(cmds[i]);
		cmds[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	return_space(cmds);
	return (cmds);
}
