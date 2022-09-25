/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:06:47 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/25 07:26:53 by rda-silv         ###   ########.fr       */
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
