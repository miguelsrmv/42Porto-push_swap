/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 17:14:18 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	print_list_order_organized(t_ptr *stack)
{
	t_list	*current_node;
	int		length;
	char	*line;

	current_node = stack->next;
	length = stack->length;
	line = "_____________________________________________________________";
	printf("\n%s STACK %c%s\n", line, ((stack->name) - 32), line);
	printf("Value\t\tAddress\t\tPrevious\tNext\t\t\tPosition\tTarget\t\tCost\n");
	while (length--)
	{
		printf("%i\t\t%p\t%p\t%p\t\t%i\t\t%i\t\t%i\n", current_node->value,
			&(current_node->value), current_node->prev, current_node->next,
			current_node->position, current_node->target, current_node->cost);
		current_node = current_node->next;
	}
	printf("\n");
	fflush(stdout);
}

void	print_stack_data(t_ptr *stack)
{
	printf("Stack %c: Points to number: %i, Length: %i, First Address: %p\n",
		(stack->name) - 32, stack->next->value, stack->length, stack->next);
	fflush(stdout);
}

char	*print_tab_calc(t_list *prev)
{
	if (prev == NULL)
		return ("\t\t");
	else
		return ("\t");
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
