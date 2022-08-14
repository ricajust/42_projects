/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:28:02 by rda-silv          #+#    #+#             */
/*   Updated: 2022/02/19 23:05:46 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_convert(int n, char *str, size_t size, long nbr)
{
	if (n == 0)
		str[0] = '0';
	str[--size] = '\0';
	while (nbr > 0)
	{
		str[--size] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long		nbr;
	size_t		size;
	char		*str;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		size = ft_size(nbr) + 2;
		str = (char *)malloc(size * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		size = ft_size(nbr) + 1;
		str = (char *)malloc(size * sizeof(char));
		if (!str)
			return (NULL);
	}
	return (ft_convert(n, str, size, nbr));
}
