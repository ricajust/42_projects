/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 21:27:47 by rda-silv          #+#    #+#             */
/*   Updated: 2021/09/02 22:01:25 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_cntwrd(char const *s, char c)
{
	size_t	i;
	size_t	wrd;

	i = 0;
	wrd = 0;
	while ((s[i] == c) && (s[i] != '\0'))
		i++;
	while (s[i] != '\0')
	{
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		wrd++;
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
	}
	return (wrd);
}

static size_t	ft_wrdlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	wrd;
	char	**spl;

	if (!s)
		return (0);
	j = 0;
	i = 0;
	wrd = ft_cntwrd(s, c);
	spl = (char **)malloc((wrd + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	while (s[j] != '\0')
	{
		if ((s[j] != c) && (s[j] != '\0'))
		{
			spl[i++] = ft_substr(s, j, ft_wrdlen(&s[j], c));
			j = (j + ft_wrdlen(&s[j], c) - 1);
		}
		j++;
	}
	spl[i] = NULL;
	return (spl);
}
