/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:54 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/11 16:41:16 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path_in_env(char **envp)
{
	int		i;
	char	*env_path;

	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
		{
			env_path = ft_substr(env_path, 0, ft_strlen(env_path));
			return (env_path);
		}
		i++;
	}
	return (0);
}

char	*find_command(char *command_with_flag, t_data *data)
{
	int		i;
	char	*env_path;
	char	**paths;
	char	*path_and_command;

	data->command_and_flags = ft_split(command_with_flag, ' ');
	env_path = find_path_in_env(data->envp);
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		path_and_command = ft_strjoin(paths[i], data->command_and_flags[0]);
		if (access(path_and_command, F_OK | X_OK) == 0)
			return (path_and_command);
		i++;
		free(path_and_command);
	}
	return (0);
}
