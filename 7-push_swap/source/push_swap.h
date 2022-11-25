/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:39:49 by rda-silv          #+#    #+#             */
/*   Updated: 2022/11/24 22:07:00 by rda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

//Structs
typedef struct _snode {
	int				val;
	struct _snode	*next;
}	t_snode;

typedef struct _linked_list {
	t_snode	*begin;
}	t_linkded_list;

//Functions
/**
 * @brief Create a info for linked list
 * 
 * @return t_linkded_list* return a pointer to list begin
 */
t_linkded_list	*ft_create_linked_list(void);

/**
 * @brief Create a new node in linked list
 * 
 * @param val integer value
 * @return t_snode* pointer to next node
 */
t_snode			*ft_create_node(int val);

/**
 * @brief Add a new node in begin of linked list
 * 
 * @param linked_list pointer for linked list
 * @param val integer value used by node
 */
void			ft_add_first(t_linkded_list *linked_list, int val);

/**
 * @brief 
 * 
 */
void			ft_print_list(const t_linkded_list *list);

#endif