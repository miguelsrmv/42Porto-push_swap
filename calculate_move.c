/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:07:37 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/02 18:46:02 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

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

int	min_cost(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (min < b)
		min = b;
	if (min < c)
		min = c;
	if (min < d)
		min = d;
	return (min);
}


int	max_val(int a, int b)
{
	if (a >= b)
		return (a);
	if (b < a)
		return (b);
}

int	movement_cost(t_ptr **stack_a, t_ptr **stack_b, int length_a)
{
	t_list	*a_node;
	int		a_up_b_up;
	int		a_down_b_down;
	int		a_up_b_down;
	int		a_down_b_up;

	a_node = (*stack_a)->next;
	while (length_a--)
	{
		a_up_b_up = 1 + max_val(a_node->position, a_node->position);
		a_down_b_down = 1 + max_val(a_node->rev_position, a_node->rev_position);
		a_up_b_down = 1 + a_node->position + a_node->rev_position;
		a_down_b_up = 1 + a_node->rev_position + a_node->position;
		(*stack_a)->next->cost = min_cost(a_up_b_down, a_down_b_down,
				a_up_b_down, a_down_b_up);
		if ((*stack_a)->next->cost == a_up_b_up)
			(*stack_a)->next->course = 'A';
		else if ((*stack_a)->next->cost == a_down_b_down)
			(*stack_a)->next->course = 'B';
		else if ((*stack_a)->next->cost == a_up_b_down)
			(*stack_a)->next->course = 'C';
		else
			(*stack_a)->next->course = 'D';
		a_node = a_node->next;
	}
}
