/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:32:15 by rda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 22:14:47 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_linkded_list	*list;

	list = ft_create_linked_list();
	ft_add_first(list, 5);
	ft_print_list(list);
	ft_add_first(list, 4);
	ft_print_list(list);
	ft_add_first(list, 2);
	ft_print_list(list);
	ft_add_first(list, 10);
	ft_print_list(list);
	return (0);
}
