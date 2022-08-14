/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:36:32 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 16:48:13 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*memory_alloction(const char *s1)
{
	char	*cpy;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static void	cpy_n_return(char *dest, const char *src, size_t size_src)
{
	size_t	i;
	size_t	size_dest;

	if (!dest && !src)
		return ;
	i = 0;
	size_dest = 0;
	size_dest = ft_strlen(dest);
	ft_bzero(dest, size_dest);
	while (i < size_src)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	get_lines(char **buf, char **line, char *data_main)
{
	int		i;
	int		strlen_data;
	char	*tmp_data;

	i = 0;
	strlen_data = 0;
	tmp_data = memory_alloction("");
	while (buf[0][i] != '\n' && buf[0][i] != '\0')
		i++;
	if (buf[0][i] == '\n')
	{
		line[0] = ft_substr(buf[0], 0, i + 1);
		free(tmp_data);
		tmp_data = memory_alloction(&buf[0][i + 1]);
	}
	else
		line[0] = memory_alloction(buf[0]);
	strlen_data = ft_strlen(tmp_data);
	cpy_n_return(data_main, tmp_data, strlen_data);
	free(tmp_data);
}

static char	*ft_reader(char *data_main, char **buf, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (buf[0][j])
		j++;
	while (!ft_strchr(buf[0], '\n') && i)
	{
		i = read(fd, data_main, BUFFER_SIZE);
		j += i;
		if (i <= 0)
			break ;
		buf[0] = ft_strjoin(buf[0], data_main);
		buf[0][j] = '\0';
	}
	if (i < 0)
		return (NULL);
	else if (i == 0 && j == 0)
		return (NULL);
	get_lines(buf, &line, data_main);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	data_main[BUFFER_SIZE + 1];
	char		*reader;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (!data_main[0])
		buf = memory_alloction("");
	else
		buf = memory_alloction(data_main);
	reader = ft_reader(data_main, &buf, fd);
	free(buf);
	return (reader);
}
