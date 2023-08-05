/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:07:37 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/05 21:50:13 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdlib.h>


int	min_cost(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
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

void	calculate_cost(t_list **stack_a, t_cost *cost)
{
	cost = (t_cost *)malloc(sizeof(t_cost));
	if (!cost)
	{
		free(cost);
		return ;
	}
	cost->a_up_b_up = 1 + max_val((*stack_a)->next->position,
			(*stack_a)->next->target);
	cost->a_down_b_down = 1 + max_val((*stack_a)->next->rev_position,
			(*stack_a)->next->rev_target);
	cost->a_up_b_down = 1 + (*stack_a)->next->position
		+ (*stack_a)->next->rev_target;
	cost->a_down_b_up = 1 + (*stack_a)->next->rev_position
		+ (*stack_a)->next->target;
	(*stack_a)->next->cost = min_cost(cost->a_up_b_up, cost->a_down_b_down,
			cost->a_up_b_down, cost->a_down_b_up);
	if ((*stack_a)->next->cost == cost->a_up_b_up)
		(*stack_a)->next->pattern = 'a';
	else if ((*stack_a)->next->cost == cost->a_down_b_down)
		(*stack_a)->next->pattern = 'b';
	else if ((*stack_a)->next->cost == cost->a_up_b_down)
		(*stack_a)->next->pattern = 'c';
	else
		(*stack_a)->next->pattern = 'd';
	free(cost);
}

int	movement_cost(t_ptr **stack_a, t_ptr **stack_b, int length_a)
{
	t_list	*a_node;
	t_cost	*cost;

	a_node = (*stack_a)->next;
	while (length_a--)
	{
		calculate_cost(&a_node, cost);
		a_node = a_node->next;
	}
}

t_ptr	*get_min_cost_node(t_ptr **stack_a)
{
	t_ptr	*a_node;
	t_ptr	*cost_node;
	int		length;

	a_node = (*stack_a);
	cost_node = (*stack_a);
	length = (*stack_a)->length;
	while (length--)
	{
		if (cost_node->next->cost < a_node->next->cost)
			cost_node->next = a_node->next;
		a_node->next = a_node->next->next;
	}
	return (cost_node);
}
