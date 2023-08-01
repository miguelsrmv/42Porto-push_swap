/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 17:03:55 by mde-sa--         ###   ########.fr       */
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
		printf("Value of a_node: %i, b_node: %i", a_node->value, b_node->value);
		fflush(stdout);
		while (a_node->value > b_node->value && max_iteration--)
			b_node = b_node->next;
		if (a_node->value < b_node->value)
		{
			a_node->target = b_node->position;
			a_node = a_node->next;
		}
		else if (max_iteration == 0)
			a_node->target = 1;
	}
}




/*
void	sort_list(t_list **starting_node, int length)
{
	int		rotate_back;
	int		length_copy;
	t_list	*current_node;
	t_list	*buffer_node;

	bit = 0;
	buffer_node = ft_lstnew(&rotate_back, 1);
	current_node = *starting_node;
	while (++bit)
	{
		/* printf("\n\n");
		printf("STACK A: \n\n");
		print_list_order_organized(current_node);
		printf("\n\n");
		printf("STACK B: \n\n");
		print_list_order_organized(buffer_node);
		printf("\n\n"); 
		if (is_a_sorted(ft_lstfirst(current_node), buffer_node))		// DAR FREE!!!!
			return ;
		rotate_back = 0;
		length_copy = length;
		while (length_copy--)
		{	
			if ((((current_node->sorted) >> (bit - 1)) & 1) == 0)
				pb(&current_node, buffer_node, &rotate_back);
			else
				ra(&current_node);
		}
		while (rotate_back)
			pa(&current_node, buffer_node, &rotate_back);
	}
} */