/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 12:10:29 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

// Creates linked list and parses through argvs to check they are all correct
int	create_linked_list(char **argv, t_list **starting_node)
{
	long	value_from_argument;
	t_list	*current_node;

	value_from_argument = ft_atol(*argv);
	*starting_node = ft_lstnew(&value_from_argument);
	current_node = *starting_node;
	argv++;
	while (*argv)
	{
		value_from_argument = ft_atol(*argv);
		if (check_arg_validity(*argv, value_from_argument) == 0)
		{
			if (*starting_node)
				ft_lstclear(*starting_node);
			return (0);
		}
		else
		{
			ft_lstadd_back(starting_node, ft_lstnew(&value_from_argument));
			current_node = current_node->next;
		}
		argv++;
	}
	return (1);
}

void	create_stacks(t_list **starting_node, t_ptr **stack_a, t_ptr **stack_b, int length)
{
	t_list	*last_a_node;

	*stack_a = (t_ptr *)malloc(sizeof(t_ptr));
	*stack_b = (t_ptr *)malloc(sizeof(t_ptr));
	if (!(*stack_a) || !(*stack_b))
		return ;
	(*stack_a)->name = 'a';
	(*stack_b)->name = 'b';
	(*stack_a)->length = length - 2;
	(*stack_b)->length = 2;
	(*stack_a)->next = (*starting_node)->next->next;
	last_a_node = ft_lstlast((*stack_a)->next);
	(*stack_a)->next->prev = last_a_node;
	(last_a_node)->next = (*stack_a)->next;
	(*stack_b)->next = *starting_node;
	(*stack_b)->next->next->next = (*stack_b)->next;
	(*stack_b)->next->prev = (*stack_b)->next->next;

	(*starting_node) = (*stack_a)->next;
	write(1, "pb\npb\n", 6);
}
