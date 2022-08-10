/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:52:16 by rda_silva         #+#    #+#             */
/*   Updated: 2022/02/19 15:35:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_mount_line(char *src, int fd)
{
	char	*buffer;
	int		str_len;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	str_len = 1;
	while (!ft_strchr(src, '\n') && str_len != 0)
	{
		str_len = read(fd, buffer, BUFFER_SIZE);
		if (str_len == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[str_len] = '\0';
		src = ft_strjoin(src, buffer);
	}
	free (buffer);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved_content;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved_content = ft_mount_line(saved_content, fd);
	if (saved_content == NULL)
		return (NULL);
	line = ft_read_line(saved_content);
	saved_content = ft_save_rest(saved_content);
	if (line[0] == '\0')
	{
		free(saved_content);
		free(line);
		return (NULL);
	}
	return (line);
}
