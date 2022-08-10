/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:58:14 by rda-silv          #+#    #+#             */
/*   Updated: 2021/08/28 16:40:58 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;

	if (s1 && s2)
	{
		newstr = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (newstr)
		{
			i = 0;
			while (*s1 != '\0')
				newstr[i++] = *s1++;
			while (*s2 != '\0')
				newstr[i++] = *s2++;
			newstr[i++] = '\0';
			return (newstr);
		}
	}
	return (NULL);
}
