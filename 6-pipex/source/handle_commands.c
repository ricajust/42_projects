/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:06:47 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/28 08:23:31 by rda-silv         ###   ########.fr       */
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

void	return_space(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '.')
			command[i] = 32;
		(i)++;
	}

}

char	**handle_command_and_flag(char *command)
{
	int		flag;
	int		i;
	char	**cmds;
	char	*temp;

	flag = 0;
	i = 0;
	while (command[i])
	{
		if (command[i] == 39 && flag == 0)
			flag = replace_space(command, &i);
		i++;
	}
	cmds = ft_split(command, 32);
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
	i = 0;
	while (cmds[i])
	{
		return_space(cmds[i]);
		i++;
	}
	return (cmds);
}
