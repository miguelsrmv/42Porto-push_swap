/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:42:16 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/12 15:44:08 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	create_instruction_list();
	test_instruction();
	free_allocs(&stack_a, &stack_b);
	return (0);
}
