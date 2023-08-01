/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:59:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 15:10:27 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	push(t_ptr **stack_from, t_ptr **stack_to)
{
	t_list	*temp_node;

	temp_node = (*stack_from)->next;
	(*stack_from)->next = (*stack_from)->next->next;
	temp_node->next->prev = temp_node->prev;
	temp_node->prev->next = temp_node->next;
	temp_node->next = (*stack_to)->next;
	temp_node->prev = (*stack_to)->next->prev;
	(*stack_to)->next->prev->next = temp_node;
	(*stack_to)->next->prev = temp_node;
	(*stack_to)->next = temp_node;
	((*stack_from)->length)--;
	((*stack_to)->length)++;
	print_instruction("p", (*stack_to)->name);

}

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