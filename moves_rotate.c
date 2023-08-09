/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:46:17 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/09 18:01:48 by mde-sa--         ###   ########.fr       */
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
	write(1, "rr\n", 3);
}

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

void	rotate(t_instruct **rotate_instruct, t_ptr **stack_a,
	t_ptr **stack_b)
{
	while ((*rotate_instruct)->a-- > 0)
		rotate_stack(stack_a);
	while ((*rotate_instruct)->b-- > 0)
		rotate_stack(stack_b);
	while ((*rotate_instruct)->both-- > 0)
		rotate_both(stack_a, stack_b);
	(*rotate_instruct)->a++;
	(*rotate_instruct)->b++;
	(*rotate_instruct)->both++;
	while ((*rotate_instruct)->a++ < 0)
		reverse_rotate_stack(stack_a);
	while ((*rotate_instruct)->b++ < 0)
		reverse_rotate_stack(stack_b);
	while ((*rotate_instruct)->both++ < 0)
		reverse_rotate_both(stack_a, stack_b);
	(*rotate_instruct)->a--;
	(*rotate_instruct)->b--;
	(*rotate_instruct)->both--;
}
