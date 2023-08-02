/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/02 14:15:08 by mde-sa--         ###   ########.fr       */
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
	create_stacks(&starting_node, &stack_a, &stack_b, argc - 1);
	test_input(&stack_a, &stack_b);
	/*
	print_stack_data(stack_b);
	reset_nodes(&stack_a, &stack_b);
	find_correct_position(&stack_a, &stack_b);
	check_sorted(&stack_a, &stack_b);
	print_list_order_organized(stack_a);
	print_list_order_organized(stack_b);
	*/
	// Sort it
		// sort_list(&starting_node, argc - 1);
	// Delete the entirety of the linked list
	return (0);
}


// Tarefas
// 1 Correct push_a e push_b em casos de 0, 1 ou 2 nodes
// 2 Confirmar que swap / rotate / reverse rotate funciona em casos de 2 nodes
