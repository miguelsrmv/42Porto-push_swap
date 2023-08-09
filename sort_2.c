/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:17:58 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/09 18:12:15 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	small_sort_3(t_ptr **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->next->value;
	b = (*stack)->next->next->value;
	c = (*stack)->next->next->next->value;
	if (a < b && b < c && a < c)///////123
		return ;
	else if (a < b && b > c && a < c)//132
	{
		reverse_rotate_stack(stack);
		swap_stack(stack);
	}
	else if (a < b && b > c && a > c)//231
		reverse_rotate_stack(stack);
	else if (a > b && b > c && a > c)//321
	{
		swap_stack(stack);
		reverse_rotate_stack(stack);
	}
	else if (a > b && b < c && a > c)//312
		rotate_stack(stack);
	else//////////////////////////////213
		swap_stack(stack);
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
			min_targets(&a_node, stack_b);
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
			max_targets(&b_node, stack_a);
		b_node = b_node->next;
	}
}

void	max_targets(t_list **node, t_ptr **stack_a)
{
	t_list	*a_node;

	a_node = (*stack_a)->next;
	while (a_node->next->value > a_node->value)
		a_node = a_node->next;

	(*node)->target = a_node->position + 1;
	(*node)->rev_target = a_node->rev_position - 1;
}

void	min_targets(t_list **node, t_ptr **stack_b)
{
	t_list	*b_node;

	b_node = (*stack_b)->next;
	while (b_node->next->value < b_node->value)
		b_node = b_node->next;

	(*node)->target = b_node->position + 1;
	(*node)->rev_target = b_node->rev_position - 1;
}

void	correct_targets(t_list **node, int length)
{
	(*node)->target = length;
	(*node)->rev_target = 0;
}

void	rotate_back_pattern(t_ptr **stack_a, t_ptr **stack_b, int length)
{
	int		min_move;

	if (((*stack_b)->next->target) <= ((*stack_b)->next->rev_target))
	{
		min_move = (*stack_b)->next->target;
		while (min_move--)
			rotate_stack(stack_a);
	}
	else
	{
		min_move = (*stack_b)->next->rev_target;
		while (min_move--)
			reverse_rotate_stack(stack_a);
	}
/*
	min_target = (*stack_b)->next->target;
	max_rev_target = (*stack_b)->next->rev_target;
	b_node = (*stack_b)->next;
	while (length--)
	{
		if (min_target > b_node->next->target)
			min_target = b_node->next->target;
		if (max_rev_target > b_node->next->rev_target)
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
*/
}

void	rotate_back_and_push(t_ptr **stack_a, t_ptr **stack_b)
{
	int	min_move;

	if ((*stack_b)->next->target <= (*stack_b)->next->rev_target)
	{
		min_move = ((*stack_b)->next->target);
		while (min_move--)
			rotate_stack(stack_a);
	}
	else
	{
		min_move = ((*stack_b)->next->rev_target);
		while (min_move--)
			reverse_rotate_stack(stack_a);
	}
	push(stack_b, stack_a);
}

void	final_rotate_back(t_ptr **stack_a)
{
	t_ptr	*min_node;
	int		min_move;
	
	min_node = (t_ptr *)malloc(sizeof(t_ptr));
	if (!min_node)
		return ;
	min_node->next = (*stack_a)->next;
	while (min_node->next->value < min_node->next->next->value)
		min_node->next = min_node->next->next;
	min_node->next = min_node->next->next;
	if (min_node->next->position <= min_node->next->rev_position)
	{
		min_move = min_node->next->position;
		while ((min_move)--)
			rotate_stack(stack_a);
	}
	else
	{
		min_move = min_node->next->rev_position;
		while ((min_move)--)
			reverse_rotate_stack(stack_a);
	}
	free (min_node);
}
