/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:04:24 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/05 19:08:10 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_poc.h"

char	*get_command_path(char *command, char **envp)
{
	// char	*aux;
	int		i;
	char	*envp_path;
	char	*path;
	char	**paths;
	// char	*tmp;

	ft_printf("Command input was: %s\n\n", command);
	i = 0;
	while (envp[i])
	{
		envp_path = ft_strnstr(envp[i], "PATH=", 5);
		if (envp_path)
			path = ft_strdup(ft_strchr(envp_path, '=') + 1);
		i++;
	}
	paths = ft_split(path, ':');
	free(path);
	path = NULL;
	i = 0;
	while (paths[i])
	{
		printf("entrou %d\n", i);
		i++;
	}
	free(paths);
	paths = NULL;
	return (0);
}
