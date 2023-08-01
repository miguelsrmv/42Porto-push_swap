/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:59:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 11:25:53 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// Reverse rotates stack
void	reverse_rotate_stack(t_ptr **stack)
{
	(*stack)->next = (*stack)->next->prev;
	print_instruction("rr", (*stack)->name);
}

void	reverse_rotate_both(t_ptr **stack_a, t_ptr **stack_b)
{
	(*stack_a)->next = (*stack_a)->next->prev;
	(*stack_b)->next = (*stack_b)->next->prev;
	write(1, "rrr\n", 4);
}
