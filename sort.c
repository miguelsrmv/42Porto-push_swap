/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/31 17:48:28 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	pb(t_list **current_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*final_b_node;

	final_b_node = ft_lstlast(buffer_node);
	*current_node = (*current_node)->next;
	final_b_node->next = (*current_node)->prev;
	final_b_node->next->prev = final_b_node;
	final_b_node->next->next = NULL;
	(*current_node)->prev = NULL;
	(*rotate_back)++;
	write(1, "pb\n", 3);
}

void	pa(t_list **current_node, t_list *buffer_node, int *rotate_back)
{
	t_list	*final_b_node;

	final_b_node = ft_lstlast(buffer_node);
	(*current_node)->prev = final_b_node;
	final_b_node->prev->next = NULL;
	final_b_node->next = *current_node;
	*current_node = (*current_node)->prev;
	(*current_node)->prev = NULL;
	(*rotate_back)--;
	write(1, "pa\n", 3);
}

// Rotates List A
void	ra(t_list **current_node)
{
	t_list	*final_a_node;

	final_a_node = ft_lstlast(*current_node);
	final_a_node->next = *current_node;
	*current_node = (*current_node)->next;
	(*current_node)->prev->prev = final_a_node;
	(*current_node)->prev = NULL;
	final_a_node->next->next = NULL;
	write(1, "ra\n", 3);
}

int	is_a_sorted(t_list *current_node, t_list *buffer_node)
{
	t_list	*check_node;

	check_node = current_node;
	while (check_node->next)
	{
		if (check_node->next->value > check_node->value)
			check_node = check_node->next;
		else
			break ;
	}
	if (check_node->next == NULL)
	{
/* 		ft_lstclear(current_node);
		ft_lstclear(buffer_node); */
		return (1);
	}
	else
		return (0);
}

void	sort_list(t_list **starting_node, int length)
{
	int		bit;
	int		rotate_back;
	int		length_copy;
	t_list	*current_node;
	t_list	*buffer_node;

	bit = 0;
	buffer_node = ft_lstnew(&rotate_back, 1);
	current_node = *starting_node;
	while (++bit)
	{
		/* printf("\n\n");
		printf("STACK A: \n\n");
		print_list_order_organized(current_node);
		printf("\n\n");
		printf("STACK B: \n\n");
		print_list_order_organized(buffer_node);
		printf("\n\n"); */
		if (is_a_sorted(ft_lstfirst(current_node), buffer_node))		// DAR FREE!!!!
			return ;
		rotate_back = 0;
		length_copy = length;
		while (length_copy--)
		{	
			if ((((current_node->sorted) >> (bit - 1)) & 1) == 0)
				pb(&current_node, buffer_node, &rotate_back);
			else
				ra(&current_node);
		}
		while (rotate_back)
			pa(&current_node, buffer_node, &rotate_back);
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
