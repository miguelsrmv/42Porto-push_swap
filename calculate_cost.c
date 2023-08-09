/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:07:37 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/09 14:25:34 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <unistd.h>
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
	cost->a_up_b_up = 1 + max_val((*stack_a)->position,
			(*stack_a)->target);
	cost->a_down_b_down = 1 + max_val((*stack_a)->rev_position,
			(*stack_a)->rev_target);
	cost->a_up_b_down = 1 + (*stack_a)->position
		+ (*stack_a)->rev_target;
	cost->a_down_b_up = 1 + (*stack_a)->rev_position
		+ (*stack_a)->target;
	(*stack_a)->cost = min_cost(cost->a_up_b_up, cost->a_down_b_down,
			cost->a_up_b_down, cost->a_down_b_up);
	if ((*stack_a)->cost == cost->a_up_b_up)
		(*stack_a)->pattern = 'a';
	else if ((*stack_a)->cost == cost->a_down_b_down)
		(*stack_a)->pattern = 'b';
	else if ((*stack_a)->cost == cost->a_up_b_down)
		(*stack_a)->pattern = 'c';
	else
		(*stack_a)->pattern = 'd';
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
/*
t_ptr	*get_min_cost_node(t_ptr **stack_a)
{
	t_ptr	*cost_node;
	t_list	*a_node;
	int		length;

	a_node = (*stack_a)->next;
	cost_node = (*stack_a);
	length = (*stack_a)->length;
	while (length--)
	{
		if (cost_node->next->cost > a_node->cost)
			cost_node->next = a_node;
		a_node = a_node->next;
	}
	return (cost_node);
}
*/

t_ptr	*get_min_cost_node(t_ptr *stack_a)
{
	t_ptr	*cost_node;
	t_list	*a_node;
	int		length;

	a_node = stack_a->next;
	cost_node = (t_ptr *)malloc(sizeof(t_ptr));
	if (!cost_node)
		return (NULL);
	cost_node->next = stack_a->next;
	length = stack_a->length;
	while (length--)
	{
		if (cost_node->next->cost > a_node->cost)
			cost_node->next = a_node;
		a_node = a_node->next;
	}
	return (cost_node);
}
