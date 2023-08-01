/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:59:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 11:00:36 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*
void	pb(t_list **current_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*final_b_node;

	final_b_node = ft_lstlast(buffer_node);
	*current_node = (*current_node)->next;
	final_b_node->next = (*current_node)->prev;
	final_b_node->next->prev = final_b_node;
	final_b_node->next->next = NULL;
	(*current_node)->prev = NULL;
	(*rotate_back)++;
	write(1, "pb\n", 3);
}

void	pa(t_list **current_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*final_b_node;

	final_b_node = ft_lstlast(buffer_node);
	(*current_node)->prev = final_b_node;
	final_b_node->prev->next = NULL;
	final_b_node->next = *current_node;
	*current_node = (*current_node)->prev;
	(*current_node)->prev = NULL;
	(*rotate_back)--;
	write(1, "pa\n", 3);
}
*/