/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:36:34 by rda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 22:48:16 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c >= 256)
		c -= 256;
	i = 0;
	while ((s[i] != '\0') && (s[i] != c))
		i++;
	if ((char)c == s[i])
		return ((char *)s + i);
	else
		return (0);
}