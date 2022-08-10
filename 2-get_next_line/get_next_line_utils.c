/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:07:27 by rda_silva         #+#    #+#             */
/*   Updated: 2022/02/19 15:35:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str_1, char *str_2)
{
	char	*str_3;
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;

	len_1 = 0;
	if (str_1)
		len_1 = ft_strlen(str_1);
	len_2 = ft_strlen(str_2);
	str_3 = (char *)malloc(len_1 + len_2 + 1);
	if (str_3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (str_1 != 0)
		while (j < len_1)
			str_3[i++] = str_1[j++];
	j = 0;
	while (j < len_2)
		str_3[i++] = str_2[j++];
	free(str_1);
	str_3[i] = '\0';
	return (str_3);
}

char	*ft_strchr(char *src, int c)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (c == '\0')
		return ((char *)&src[ft_strlen(src)]);
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}

char	*ft_read_line(char *src)
{
	size_t	i;
	char	*str;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_save_rest(char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (src[i] == '\0')
	{
		free (src);
		return (0);
	}
	str = (char *)malloc((ft_strlen(src) - i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (src[i] != '\0')
		str[j++] = src[i++];
	str[j] = '\0';
	free (src);
	return (str);
}
