/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:03:33 by rda-silv          #+#    #+#             */
/*   Updated: 2021/09/01 20:14:11 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	lenstr;
	size_t	i;
	size_t	end;

	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	if (start > lenstr)
		return (ft_strdup(""));
	if (len > lenstr)
		substr = malloc(sizeof(char) * (lenstr + 1));
	else if (len == lenstr)
		substr = malloc(sizeof(char) * ((len - start) + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	end = len + start;
	while ((start < end) && (s[start] != '\0'))
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
