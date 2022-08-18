/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:36:08 by rda-silv          #+#    #+#             */
/*   Updated: 2021/09/01 20:59:59 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dt, const void *sr, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if (!dt && !sr)
		return (0);
	dest = (unsigned char *)dt;
	src = (unsigned char *)sr;
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
