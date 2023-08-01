/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:46:17 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 11:20:40 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// Rotates stack
void	rotate_stack(t_ptr **stack)
{
	(*stack)->next = (*stack)->next->next;
	print_instruction("r", (*stack)->name);
}

// Rotates both stacks
void	rotate_both(t_ptr **stack_a, t_ptr **stack_b)
{
	(*stack_a)->next = (*stack_a)->next->next;
	(*stack_b)->next = (*stack_b)->next->next;
	print_instruction("rr", 'r');
}
