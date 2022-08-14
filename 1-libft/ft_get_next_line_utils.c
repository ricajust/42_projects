/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:36:25 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 16:53:08 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlena(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

char	*ft_strjoina(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	i = -1;
	lens1 = ft_strlena (s1);
	lens2 = ft_strlena (s2);
	str = malloc((lens2 + lens1 + 1) * sizeof(char));
	while (++i < lens1)
		str[i] = s1[i];
	i = -1;
	while (++i < lens2)
		str[i + lens1] = s2[i];
	str[lens1 + lens2] = '\0';
	free (s1);
	s1 = NULL;
	return (str);
}

char	*ft_substra(char const *s, unsigned int start, size_t len)
{
	size_t	strlen1;
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	strlen1 = ft_strlen (s);
	if ((strlen1 + 1) < len + 1)
		ptr = (char *)malloc(strlen1 + 1);
	else if (len == strlen1)
		ptr = (char *)malloc((len - start) + 1);
	else
		ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while ((i < len) && (start + i) < strlen1)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	strlen1;

	strlen1 = ft_strlena(s);
	i = 0;
	if (c == '\0')
		return ((char *) s + strlen1);
	if (c > 256)
		c -= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}
