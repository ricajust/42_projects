/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_poc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:42:22 by rda-silv          #+#    #+#             */
/*   Updated: 2022/09/04 21:38:47 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_POC_H
# define PIPEX_POC_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include "./../library/libft/libft.h"

/**
 * @brief Get the command path object
 * 
 * @param command pointer to inserted command
 * @param envp pointer to environment variable
 * @return char 
 */
char	*get_command_path(char *command, char **envp);

/**
 * @brief arguments validator
 * 
 * @param argc 
 * @param argv 
 */
void	argc_validator(int argc);

#endif