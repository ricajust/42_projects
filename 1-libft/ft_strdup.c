/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:24:28 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 16:34:23 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(str) + 1;
	dst = malloc(len * sizeof(char));
	if (dst)
		(ft_strlcpy(dst, str, len));
	return (dst);
}
