/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:19:47 by rda-silv          #+#    #+#             */
/*   Updated: 2021/08/15 22:17:28 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	littlelen;

	littlelen = ft_strlen(little);
	if (!(*little))
		return ((char *)big);
	i = 0;
	while (*big && (i <= len))
	{
		if (ft_strncmp(big, little, littlelen) == 0 && (i + littlelen <= len))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
