/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:58:14 by rda-silv          #+#    #+#             */
/*   Updated: 2022/08/14 16:36:32 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*conc;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = -1;
	size_s1 = 0;
	size_s2 = 0;
	while (s1[size_s1])
		size_s1++;
	while (s2[size_s2])
		size_s2++;
	conc = malloc((size_s2 + size_s1 + 1) * sizeof(char));
	while (++i < size_s1)
		conc[i] = s1[i];
	i = -1;
	while (++i < size_s2)
		conc[i + size_s1] = s2[i];
	conc[size_s2 + size_s1] = '\0';
	free(s1);
	return (conc);
}
