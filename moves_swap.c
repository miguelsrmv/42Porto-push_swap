/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:00:06 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 22:27:18 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_stack(t_ptr **stack)
{
	swap(&(*stack)->next->value, &(*stack)->next->next->value);
	print_instruction("s", (*stack)->name);
}

void	swap_both(t_ptr **stack_a, t_ptr **stack_b)
{
	swap(&(*stack_a)->next->value, &(*stack_a)->next->next->value);
	swap(&(*stack_b)->next->value, &(*stack_b)->next->next->value);
	print_instruction("s", 's');
}
