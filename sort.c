/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 17:39:47 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

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
		temp_node->position = length_a + 1;
		temp_node->target = 0;
		temp_node->cost = 0;
	}
	temp_node = (*stack_b)->next;
	length_b = (*stack_b)->length;
	while (length_b--)
	{
		temp_node = temp_node->prev;
		temp_node->position = length_b + 1;
		temp_node->target = 0;
		temp_node->cost = 0;
	}
}

void	find_correct_position(t_ptr **stack_a, t_ptr **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		max_iteration;

	a_node = (*stack_a)->next;
	while (a_node->target == 0)
	{
		b_node = (*stack_b)->next;
		max_iteration = (*stack_b)->length;
		while (a_node->value > b_node->value && max_iteration--)
			b_node = b_node->next;
		if (a_node->value < b_node->value)
		{
			a_node->target = b_node->position;
		}
		else if (max_iteration == -1)
			a_node->target = 1;
		a_node = a_node->next;
	}
}

int	check_sorted(t_ptr **stack_a, t_ptr **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;

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

void	sort(t_ptr **stack_a, t_ptr **stack)
{
	
}
