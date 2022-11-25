/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:07:30 by rda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 22:14:16 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_linkded_list	*ft_create_linked_list(void)
{
	t_linkded_list	*list;

	list = (t_linkded_list *) malloc(sizeof(t_linkded_list));
	list->begin = NULL;
	return (list);
}

t_snode	*ft_create_node(int val)
{
	t_snode	*snode;

	snode = (t_snode *) malloc(sizeof(t_snode));
	snode->val = val;
	snode->next = NULL;
	return (snode);
}

void	ft_add_first(t_linkded_list *list, int val)
{
	t_snode	*node;

	node = ft_create_node(val);
	node->next = list->begin;
	list->begin = node;
}

void	ft_print_list(const t_linkded_list *list)
{
	t_snode	*pointer;

	pointer = list->begin;
	printf("\nList -> ");
	while (pointer)
	{
		printf("%d -> ", pointer->val);
		pointer = pointer->next;
	}
	printf("NULL\n\n");
}
