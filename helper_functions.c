/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 22:14:56 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include <string.h> //for Strcmp

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
	printf("\n%sSTACK %c%s\n", line, ((stack->name) - 32), line);
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

void	test_input(t_ptr **stack_a, t_ptr **stack_b)
{
	char	move[4];

	scanf("%s", move);
	if (strcmp(move, "pa") == 0)
		push(stack_b, stack_a);
	else if (strcmp(move, "pb") == 0)
		push(stack_a, stack_b);
	else if (strcmp(move, "sa") == 0)
		swap_stack(stack_a);
	else if (strcmp(move, "sb") == 0)
		swap_stack(stack_b);
	else if (strcmp(move, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (strcmp(move, "ra") == 0)
		rotate_stack(stack_a);
	else if (strcmp(move, "rb") == 0)
		rotate_stack(stack_b);
	else if (strcmp(move, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (strcmp(move, "rra") == 0)
		reverse_rotate_stack(stack_a);
	else if (strcmp(move, "rrb") == 0)
		reverse_rotate_stack(stack_b);
	else if (strcmp(move, "rrr") == 0)
		reverse_rotate_both(stack_a, stack_b);
}
