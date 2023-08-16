/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:00:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/09 23:03:07 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// Swaps values
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Swaps nodes #1 and #2 of stack
void	swap_stack(t_ptr **stack)
{
	swap(&(*stack)->next->value, &(*stack)->next->next->value);
	write(1, "s", 1);
	write(1, &(*stack)->name, 1);
	write(1, "\n", 1);
}

// Swaps nodes #1 and #2 of both stacks
void	swap_both(t_ptr **stack_a, t_ptr **stack_b)
{
	swap(&(*stack_a)->next->value, &(*stack_a)->next->next->value);
	swap(&(*stack_b)->next->value, &(*stack_b)->next->next->value);
	write(1, "ss\n", 3);
}
