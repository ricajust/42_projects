/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:45:27 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/10 21:11:30 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(unsigned int n, int len, char *ptr)
{
	ptr[len] = '\0';
	len--;
	while (len >= 0)
	{
		ptr[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (ptr);
}

char	*ft_uitoa(unsigned int n)
{
	char			*ptr;	
	int				len;
	unsigned int	aux;

	len = 0;
	aux = n;
	if (n == 0)
		len++;
	while (aux != 0)
	{
		aux = aux / 10;
		len++;
	}
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len + 1);
	ptr = ft_convert(n, len, ptr);
	return (ptr);
}
