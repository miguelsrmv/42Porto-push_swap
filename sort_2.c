/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:17:58 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/07 19:15:02 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	small_sort_3(t_ptr **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->next->value;
	b = (*stack)->next->next->value;
	c = (*stack)->next->next->next->value;
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_stack(stack);
		swap_stack(stack);
	}
	else if (a < b && b < c && a > c)
		reverse_rotate_stack(stack);
	else if (a > b && b < c && a < c)
		swap_stack(stack);
	else if (a > b && b < c && a > c)
		rotate_stack(stack);
	else
	{
		swap_stack(stack);
		reverse_rotate_stack(stack);
	}
}

// Finds position of each value on stack B JUST below each value on stack A
void	find_position_b(t_ptr **stack_a, t_ptr **stack_b, int length_a)
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
				a_node->rev_target = b_node->rev_position;
				tmp_max = b_node->value;
			}
			b_node = b_node->next;
		}
		if (a_node->target == 0 && a_node->value < (*stack_b)->next->value)
			correct_targets(&a_node, (*stack_b)->length);
		a_node = a_node->next;
	}
}

// Finds position of each value on stack A JUST above each value on stack B
void	find_position_a(t_ptr **stack_a, t_ptr **stack_b, int length_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		length_a;
	int		tmp_max;

	b_node = (*stack_b)->next;
	while (length_b--)
	{
		length_a = (*stack_a)->length;
		a_node = (*stack_a)->next;
		tmp_max = INT_MAX;
		while (length_a--)
		{
			if (a_node->value > b_node->value && a_node->value <= tmp_max)
			{
				b_node->target = a_node->position;
				b_node->rev_target = a_node->rev_position;
				tmp_max = a_node->value;
			}
			a_node = a_node->next;
		}
		if (b_node->target == 0 && b_node->value > (*stack_a)->next->value)
			correct_targets(&b_node, (*stack_a)->length);
		b_node = b_node->next;
	}
}

void	correct_targets(t_list **node, int length)
{
	(*node)->target = length;
	(*node)->rev_target = 0;
}

void	rotate_back_pattern(t_ptr **stack_a, t_ptr **stack_b, int length)
{
	int		min_target;
	int		max_rev_target;
	t_list	*b_node;

	min_target = (*stack_b)->next->target;
	max_rev_target = (*stack_b)->next->rev_target;
	b_node = (*stack_b)->next;
	while (length--)
	{
		if (min_target > b_node->next->target)
			min_target = b_node->next->target;
		if (max_rev_target < b_node->next->rev_target)
			max_rev_target = b_node->next->rev_target;
		b_node = b_node->next;
	}
	if (min_target <= (*stack_a)->length - max_rev_target)
	{
		while (min_target--)
			rotate_stack(stack_a);
	}
	else
	{
		while (max_rev_target--)
			reverse_rotate_stack(stack_a);
	}
}
