/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:35:57 by rda-silv          #+#    #+#             */
/*   Updated: 2021/08/14 11:11:39 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (!diff && (i < n))
	{
		diff = (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (diff);
}
