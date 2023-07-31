/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/31 13:09:09 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	pb(t_list **current_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*target_b_node;

	target_b_node = ft_lstlast(buffer_node);			// ft_lstfirst
	*current_node = (*current_node)->next;
	target_b_node->next = (*current_node)->prev;
	target_b_node->next->prev = target_b_node;
	(*current_node)->prev = NULL;
	
/* 	(first_b_element)->prev = *current_node;
	(*current_node)->next->prev = NULL;   //////
	(*current_node)->next = first_b_element;
	(*current_node)->prev = NULL; */

/* 
	(*buffer_node)->next = *current_node;					/// previous ?
	(*current_node)->next->prev = (*current_node)->prev;
	(*current_node)->prev->next = (*current_node)->next;
	(*current_node)->prev = *last_element;
	(*current_node)->next = NULL; */
	(*rotate_back)++;
	write(1, "pb\n", 3);
}

void	pa(t_list **starting_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*first_b_elem;

	first_b_elem = ft_lstfirst(buffer_node);	
	(first_b_elem)->next->prev = NULL;
	(first_b_elem)->next = *starting_node;
	(*starting_node)->prev = first_b_elem;
	
/* 	last_element = ft_lstlast(buffer_node);
	ft_lstadd_front(starting_node, last_element);
	(*last_b_node)->next->prev = last_element;
	(*last_b_node)->prev->next = NULL;
	(*last_b_node)->prev = NULL; */
	(*rotate_back)--;
	write(1, "pa\n", 3);
}

// Rotates List A
void	ra(t_list **starting_node)
{
	t_list	*last_a_node;

	printf("Starting_node %i", (*starting_node)->value);
	fflush(stdout);
	last_a_node = ft_lstlast(*starting_node);
	(last_a_node)->prev->next = NULL;
	(last_a_node)->next = *starting_node;
	(*starting_node)->prev = last_a_node;
	(last_a_node)->prev = NULL;
	write(1, "ra\n", 3);
}

void	sort_list(t_list **starting_node, int length)
{
	int		bit;
	int		rotate_back;
	int		target_node;
	t_list	*current_node;
	t_list	*buffer_node;

	bit = 0;
	while (bit < 3)
	{
		rotate_back = 0;
		target_node = elem_index(ft_lstlast(*starting_node), length, bit);
		current_node = *starting_node;
		buffer_node = ft_lstnew(&rotate_back, 1);
		printf("\n\nLIST A:\n");
		print_list_order_organized(current_node);
		printf("\n\nLIST B:\n");
		print_list_order_organized(buffer_node);
		printf("\n\n\n");
		fflush(stdout);
		int i = 1;
 		while (i != 0)
		{	
			if ((((current_node->sorted - 1) >> bit) & 1) == 0)
				pb(&current_node, buffer_node, &rotate_back);
			else
				ra(&current_node);
			printf("\n\nLIST A:\n");
			print_list_order_organized(current_node);
			printf("\n\nLIST B:\n");
			print_list_order_organized(buffer_node);
			printf("\n\n\n");
			fflush(stdout);
			i--;
		}
		ra(starting_node);
		while (rotate_back)
			pa(starting_node, buffer_node, &rotate_back);
		bit++;
		// del + free buffer node
	}
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
