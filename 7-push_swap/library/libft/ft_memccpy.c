/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:53:35 by rda-silv          #+#    #+#             */
/*   Updated: 2021/08/22 19:59:14 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srce;

	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	while (n--)
	{
		*dest = *srce;
		if (*dest == (unsigned char)c)
			return (dest + 1);
		dest++;
		srce++;
	}
	return (NULL);
}
