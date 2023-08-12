/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/12 16:09:01 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
}
