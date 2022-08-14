/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:02:29 by rda-silv          #+#    #+#             */
/*   Updated: 2021/08/29 17:25:35 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*substr;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && (s1[start] != '\0'))
		start++;
	end = ft_strlen(s1);
	while ((end != 0) && ft_strchr(set, s1[end]))
		end--;
	if ((int)(end - start + 1) <= 0)
		return (ft_calloc(1, 1));
	substr = ft_substr(s1, start, (end - start + 1));
	return (substr);
}
