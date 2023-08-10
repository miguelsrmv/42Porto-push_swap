/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/10 21:52:47 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list			*starting_node;
	t_ptr			*stack_a;
	t_ptr			*stack_b;

	if (argc < 3)
		return (1);
	++argv;
	if (check_args(argv) == 0 || create_linked_list(argv, &starting_node) == 0
		|| check_duplicates(starting_node) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	create_stacks(&starting_node, &stack_a, &stack_b, argc - 1);
	if (check_sorted(&stack_a) == 0)
	{
		free_allocs(&stack_a, &stack_b);
		return (0);
	}
	sort(&stack_a, &stack_b, argc);
	free_allocs(&stack_a, &stack_b);
	return (0);
}
