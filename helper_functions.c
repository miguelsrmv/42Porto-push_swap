/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 22:43:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include <string.h> //for Strcmp

void	print_list_order_organized(t_ptr *stack)
{
	t_list	*current_node;
	int		length;
	char	*line;

	current_node = stack->next;
	length = stack->length;
	line = "__________________________________________________________________";
	printf("\n%s%s\n", line, line);
	printf("\t\t\t\t\t\t\t\tSTACK %c\n", ((stack->name) - 32));
	printf("Value\t\tAddress\t\tPrevious\tNext\t\t\tPosition\tTarget\t\tCost\n");
	while (length--)
	{
		printf("%i\t\t%p\t%p\t%p\t\t%i\t\t%i\t\t%i\n", current_node->value,
			&(current_node->value), current_node->prev, current_node->next,
			current_node->position, current_node->target, current_node->cost);
		current_node = current_node->next;
	}
	printf("%s%s\n", line, line);
	printf("\n");
	fflush(stdout);
}

void	print_stack_data(t_ptr *stack)
{
	printf("Stack %c: Points to number: %i, Length: %i, First Address: %p\n",
		(stack->name) - 32, stack->next->value, stack->length, stack->next);
	fflush(stdout);
}

void	test_input(t_ptr **stack_a, t_ptr **stack_b)
{
	char	input[4];

	while (1)
	{
		printf("Move:");
		scanf("%s", input);
		execute_input(input, stack_a, stack_b);
		print_list_order_organized(*stack_a);
		//print_list_order_organized(stack_b)
	}
}

void	execute_input(char *input, t_ptr **stack_a, t_ptr **stack_b)
{

	if (strcmp(input, "pa") == 0)
		push(stack_b, stack_a);
	else if (strcmp(input, "pb") == 0)
		push(stack_a, stack_b);
	else if (strcmp(input, "sa") == 0)
		swap_stack(stack_a);
	else if (strcmp(input, "sb") == 0)
		swap_stack(stack_b);
	else if (strcmp(input, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (strcmp(input, "ra") == 0)
		rotate_stack(stack_a);
	else if (strcmp(input, "rb") == 0)
		rotate_stack(stack_b);
	else if (strcmp(input, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (strcmp(input, "rra") == 0)
		reverse_rotate_stack(stack_a);
	else if (strcmp(input, "rrb") == 0)
		reverse_rotate_stack(stack_b);
	else if (strcmp(input, "rrr") == 0)
		reverse_rotate_both(stack_a, stack_b);
}
