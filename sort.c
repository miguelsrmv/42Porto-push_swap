/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/31 15:41:01 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	pb(t_list **current_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*target_b_node;

	target_b_node = ft_lstlast(buffer_node);
	*current_node = (*current_node)->next;
	target_b_node->next = (*current_node)->prev;
	target_b_node->next->prev = target_b_node;
	target_b_node->next->next = NULL;
	(*current_node)->prev = NULL;
	(*rotate_back)++;
	write(1, "pb\n", 3);
}

void	pa(t_list **current_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*target_b_node;

	target_b_node = ft_lstlast(buffer_node);
	(*current_node)->prev = target_b_node;
	target_b_node->prev->next = NULL;
	target_b_node->next = *current_node;
	*current_node = (*current_node)->prev;
	(*current_node)->prev = NULL;
	(*rotate_back)--;
	write(1, "pa\n", 3);
}

// Rotates List A
void	ra(t_list **current_node)
{
	t_list	*last_a_node;

	last_a_node = ft_lstlast(*current_node);
	last_a_node->next = *current_node;
	*current_node = (*current_node)->next;
	(*current_node)->prev->prev = last_a_node;
	(*current_node)->prev = NULL;
	last_a_node->next->next = NULL;
	write(1, "ra\n", 3);
}

void	sort_list(t_list **starting_node, int length)
{
	int		bit;
	int		rotate_back;
	int		length_copy;
	t_list	*current_node;
	t_list	*buffer_node;

	bit = 0;
	while (bit < 4)
	{
		rotate_back = 0;
		length_copy = length;
		current_node = *starting_node;
		buffer_node = ft_lstnew(&rotate_back, 1);
		while (length_copy--)
		{	
			if ((((current_node->sorted - 1) >> bit) & 1) == 0)
				pb(&current_node, buffer_node, &rotate_back);
			else
				ra(&current_node);
		}
		while (rotate_back)
			pa(&current_node, buffer_node, &rotate_back);
		bit++;
	}
	// del + free buffer node
}

int	elem_index(t_list *last_node, int length, int bit)
{
	t_list	*current_node;
	int		count;

	current_node = last_node;
	count = 0;
	while (current_node->prev)
	{
		if ((current_node->sorted >> bit) & 1)
			break ;
		count++;
		current_node = current_node->prev;
	}
	if ((count == length - 1) && !((current_node->sorted >> bit) & 1))
		count++;
	return (length - count);
}
