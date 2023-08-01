/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 11:27:25 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list			*starting_node;
	t_ptr			*stack_a;
	t_ptr			*stack_b;
	// If there are only 1 elements, list is already sorted. 
	// Alternative: create function to check validity?
	if (argc < 3)
		return (1);
	// Checks if args are ints and if there are duplicates
	if (create_linked_list(++argv, &starting_node) == 0
		|| check_duplicates(starting_node) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// Check if it's already sorted!!!
	// If tiny list:
	// If long list:
	create_stacks(&starting_node, &stack_a, &stack_b);
	print_list_order_organized(stack_a->next, stack_a->name, argc - 1 - 2);
	print_list_order_organized(stack_b->next, stack_b->name, 2);
	reverse_rotate_stack(&stack_a);
	print_list_order_organized(stack_a->next, stack_a->name, argc - 1 - 2);
	print_list_order_organized(stack_b->next, stack_b->name, 2);
	// Sort it
		// sort_list(&starting_node, argc - 1);
	// Delete the entirety of the linked list
	return (0);
}
