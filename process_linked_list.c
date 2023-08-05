/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/05 19:11:26 by mde-sa--         ###   ########.fr       */
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

void	create_stacks(t_list **starting_node, t_ptr **stack_a,
	t_ptr **stack_b, int length)
{
	t_list	*last_a_node;

	*stack_a = (t_ptr *)malloc(sizeof(t_ptr));
	*stack_b = (t_ptr *)malloc(sizeof(t_ptr));
	if (!(*stack_a) || !(*stack_b))
		return ;
	(*stack_a)->name = 'a';
	(*stack_b)->name = 'b';
	(*stack_a)->length = length;
	(*stack_b)->length = 0;
	(*stack_a)->next = (*starting_node);
	last_a_node = ft_lstlast((*stack_a)->next);
	(*stack_a)->next->prev = last_a_node;
	(last_a_node)->next = (*stack_a)->next;
	if ((*stack_a)->length > 3)
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
}

void	print_instruction(char *instruction, char stack)
{
	int	i;

	i = 0;
	while (instruction[i])
		i++;
	write(1, instruction, i);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
