/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/16 14:42:58 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	create_stacks(t_list **starting_node, t_ptr **stack_a,
	t_ptr **stack_b, int length)
{
	t_list	*last_a_node;

	*stack_a = (t_ptr *)malloc(sizeof(t_ptr));
	*stack_b = (t_ptr *)malloc(sizeof(t_ptr));
	if (!(*stack_a) || !(*stack_b))
		return ;
	(*stack_a)->name = 'a';
	(*stack_b)->name = 'b';
	(*stack_a)->length = length;
	(*stack_b)->length = 0;
	(*stack_a)->next = (*starting_node);
	last_a_node = ft_lstlast((*stack_a)->next);
	(*stack_a)->next->prev = last_a_node;
	(last_a_node)->next = (*stack_a)->next;
}

void	reset_node(t_list **node, t_ptr **stack, int length)
{
	(*node) = (*node)->prev;
	(*node)->position = length;
	(*node)->rev_position = (*stack)->length - length;
	(*node)->target = 0;
	(*node)->rev_target = 0;
	(*node)->cost = 0;
	(*node)->pattern = ' ';
}

void	reset_stacks(t_ptr **stack_a, t_ptr **stack_b,
	int length_a, int length_b)
{
	while (length_a--)
		reset_node(&(*stack_a)->next, stack_a, length_a);
	while (length_b--)
		reset_node(&(*stack_b)->next, stack_b, length_b);
}

// Deallocate all memory
void	free_allocs(t_ptr **stack_a, t_ptr **stack_b)
{
	if (*stack_b)
		free(*stack_b);
	(*stack_a)->next->prev->next = NULL;
	(*stack_a)->next->prev = NULL;
	ft_lstclear((*stack_a)->next);
	free(*stack_a);
}
