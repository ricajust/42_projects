/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:54 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/13 08:38:58 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*find_path_in_env(char **envp)
{
	int		i;
	char	*env_path;
	char	*result;

	i = 0;
	while (envp[i])
	{
		env_path = ft_strnstr(envp[i], "PATH=", 5);
		if (env_path)
		{
			result = ft_substr(env_path, 0, ft_strlen(env_path));
			return (result);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*conc;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = -1;
	size_s1 = 0;
	size_s2 = 0;
	while (s1[size_s1])
		size_s1++;
	while (s2[size_s2])
		size_s2++;
	conc = malloc((size_s2 + size_s1 + 1) * sizeof(char));
	while (++i < size_s1)
		conc[i] = s1[i];
	i = -1;
	while (++i < size_s2)
		conc[i + size_s1] = s2[i];
	conc[size_s2 + size_s1] = '\0';
	return (conc);
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
		path_and_command = ft_strjoin_f(paths[i], data->command_and_flags[0]);
		if (access(path_and_command, F_OK | X_OK) == 0)
		{
			free(env_path);
			free_matrix(paths);
			return (path_and_command);
		}
		i++;
		free(path_and_command);
	}
	free_matrix(paths);
	ft_strdel(&env_path);
	return (0);
}
