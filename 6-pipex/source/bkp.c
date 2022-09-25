/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bkp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:06:47 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/25 07:32:27 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*handle_command(char *cmd)
{
	char	**command_and_flag;
	char	**word_without_single_quote;
	char	*command;
	char	*flag;
	char	*final_command;

	if (cmd[0] == 39 && cmd[ft_strlen(cmd) - 1] == 39)
		return (cmd);
	command_and_flag = ft_split(cmd, ' ');
	//COMANDO
	command = command_and_flag[0];
	printf("\nComand: %s", command);
	if (command[0] == 39 && command[ft_strlen(command) - 1] == 39)
	{
		printf("Entrei no if do commando\n");
		word_without_single_quote = ft_split(command, 39);
		command = word_without_single_quote[0];
	}
	printf("\nComando sem aspas simples: %s\n", command);
	final_command = ft_strjoin_f(command, " ");
	//FLAG
	flag = command_and_flag[1];
	free_matrix(command_and_flag);
	if (flag)
	{
		printf("\nFlag: %s\n", flag);
		word_without_single_quote = ft_split(flag, 39);
		flag = word_without_single_quote[0];
		free_matrix(word_without_single_quote);
		printf("\nFlag sem aspas simples: %s\n", flag);
		final_command = ft_strjoin_f(final_command, flag);
	}
	printf("\nComando final: %s\n", final_command);
	// free_matrix(command_and_flag);
	free_matrix(word_without_single_quote);
	free(command);
	free(flag);
	command = NULL;
	flag = NULL;
	return (final_command);
}

int	main(int argc, char **argv, char **envp)
{
	int		file_in;
	int		file_out;
	t_data	data;

	argc_validator(argc);
	file_in = open(argv[1], O_RDONLY);
	file_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	open_file_validator(file_in, file_out, argv[1], argv[argc - 1]);
	data.first_cmd = handle_command(argv[2]);
	data.last_cmd = handle_command(argv[3]);
	data.argv = argv;
	data.envp = envp;
	data.file_in = file_in;
	data.file_out = file_out;
	pipering(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:54 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 21:43:58 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	return (NULL);
}

char	*find_command(char *command_with_flag, t_data *data)
{
	int		i;
	char	*env_path;
	char	**paths;
	char	*path_and_command;
	char	*test;

	data->command_and_flags = ft_split(command_with_flag, ' ');
	test = handle_command(data->command_and_flags[0]);
	printf("\n----- %s -----\n", test);
	env_path = find_path_in_env(data->envp);
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		path_and_command = ft_strjoin_f(paths[i], data->command_and_flags[0]);
		if (access(path_and_command, F_OK | X_OK) == 0)
		{
			free_all(env_path, paths);
			return (path_and_command);
		}
		i++;
		free(path_and_command);
	}
	free_matrix(paths);
	ft_strdel(&env_path);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:51 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/24 21:31:37 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_file_descriptor(int file_descriptor, t_data *data)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(file_descriptor);
	close(data->file_in);
	close(data->file_out);
}

void	child_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(data->file_in, STDIN_FILENO);
	dup2(file_descriptor[1], STDOUT_FILENO);
	close(file_descriptor[0]);
	command = find_command(data->first_cmd, data);
	// printf("COMANDO LOCALIZADO: %s\n", command);
	if (!command)
	{
		close_all_file_descriptor(file_descriptor[1], data);
		exit(handle_error(data, command));
	}
	execve(command, data->command_and_flags, data->envp);
	perror("execve");
	free_matrix(data->command_and_flags);
	free(command);
	exit(EXIT_FAILURE);
}

void	parent_process(int*file_descriptor, t_data *data)
{
	char	*command;

	dup2(file_descriptor[0], STDIN_FILENO);
	// dup2(data->file_out, STDOUT_FILENO);
	close(file_descriptor[1]);
	command = find_command(data->last_cmd, data);
	if (!command)
	{
		close_all_file_descriptor(file_descriptor[0], data);
		exit(handle_error(data, command));
	}
	execve(command, data->command_and_flags, data->envp);
	free_matrix(data->command_and_flags);
	free(command);
	exit(EXIT_FAILURE);
}
