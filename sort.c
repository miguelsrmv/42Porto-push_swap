/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:42:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 11:00:21 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

/*
void	sort_list(t_list **starting_node, int length)
{
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
		printf("\n\n"); 
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
} */