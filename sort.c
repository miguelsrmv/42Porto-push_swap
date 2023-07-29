/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/29 14:40:09 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	sort_list(t_list **starting_node, int length)
{
	int		bit_slot;
	int		target_node;
	int		rotate_back;
	t_list	*current_node;

	bit_slot = 10;
	rotate_back = 0;
 	while (bit_slot <= int_to_binary(length))
	{
		target_node = elem_index(ft_lstlast(*starting_node), length, bit_slot);
		current_node = *starting_node;
		while (target_node--)
		{
			if (current_node->binary_value % bit_slot == 0)
				write(1, "pb\n", 3);
			else
				write(1, "ra\n", 3);
			current_node = current_node->next;
			rotate_back++;
		}
		while (rotate_back--)
			write(1, "pa\n", 3);
		bit_slot *= 10;
	}
}

int	elem_index(t_list *last_node, int length, int bit_slot)
{
	t_list	*current_node;
	int		count;

	current_node = last_node;
	count = 0;
	while (current_node->prev)
	{
		if (current_node->binary_value % bit_slot == 0)
			break ;
		count++;
		current_node = current_node->prev;
	}
	if ((count == length - 1) && (current_node->binary_value % bit_slot == 1))
		count++;
	return (length - count);
}
