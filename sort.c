/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/02 17:38:02 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void	reset_nodes(t_ptr **stack_a, t_ptr **stack_b)
{
	int		length_a;
	int		length_b;
	t_list	*temp_node;

	length_a = (*stack_a)->length;
	temp_node = (*stack_a)->next;
	while (length_a--)
	{
		temp_node = temp_node->prev;
		temp_node->position = length_a;
		temp_node->rev_position = (*stack_a)->length - length_a;
		temp_node->target = 0;
		temp_node->cost = 0;
	}
	temp_node = (*stack_b)->next;
	length_b = (*stack_b)->length;
	while (length_b--)
	{
		temp_node = temp_node->prev;
		temp_node->position = length_b;
		temp_node->rev_position = (*stack_b)->length - length_b;
		temp_node->target = 0;
		temp_node->cost = 0;
	}
}

// Finds position of each value on stack B JUST below each value on stack A
void	find_position(t_ptr **stack_a, t_ptr **stack_b, int length_a)
{
	t_list	*a_node;
	t_list	*b_node;
	int		length_b;
	int		tmp_max;

	a_node = (*stack_a)->next;
	while (length_a--)
	{
		length_b = (*stack_b)->length;
		b_node = (*stack_b)->next;
		tmp_max = INT_MIN;
		while (length_b--)
		{
			if (a_node->value > b_node->value && b_node->value >= tmp_max)
			{
				a_node->target = b_node->position;
				tmp_max = b_node->value;
			}
			b_node = b_node->next;
		}
		if (a_node->target == 0 && a_node->value < (*stack_b)->next->value)
			a_node->target = (*stack_b)->length;
		a_node = a_node->next;
	}
}
// Checks if stacks are sorted
// Returns 1 if Stack A is sorted and B is rev sorted
// Returns 2 if Stack A is sorted
// Returns 3 if Stack B is rev sorted
// Returns 0 otherwise

int	check_sorted(t_ptr **stack_a, t_ptr **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;

	print_list_order_organized(*stack_a);
	print_list_order_organized(*stack_b);
	if ((*stack_a)->next)
	{
		a_node = (*stack_a)->next;
		while ((a_node->value) < (a_node->next->value))
			a_node = a_node->next;
	}
	if ((*stack_b)->next)
	{
		b_node = (*stack_b)->next;
		while ((b_node->value) > (b_node->next->value))
		b_node = b_node->next;
	}
	if (a_node == (*stack_a)->next->prev && b_node == (*stack_b)->next->prev)
		return (1);
	else if (a_node == (*stack_a)->next->prev)
		return (2);
	else if (b_node == (*stack_b)->next->prev)
		return (3);
	else
		return (0);
}

void	sort(t_ptr **stack_a, t_ptr **stack_b)
{
	while ((*stack_a)->length > 3)
	{
		reset_nodes(stack_a, stack_b);
		find_position(stack_a, stack_b, (*stack_a)->length);
		print_list_order_organized(*stack_a);
		print_list_order_organized(*stack_b);
		(*stack_a)->length = 3;
	}
}
