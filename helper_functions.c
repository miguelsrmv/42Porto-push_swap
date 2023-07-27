/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/27 17:25:13 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

void	print_list(t_list *starting_node)
{
	t_list	*current_node;

	printf("List value is: ");
	current_node = starting_node;
	while (current_node->next)
	{
		printf("%i ", current_node->value);
		current_node = current_node->next;
	}
	printf("%i \n", current_node->value);
}

void	print_list_order(t_list *starting_node)
{
	t_list	*current_node;

	printf("List index is: ");
	current_node = starting_node;
	while (current_node->next)
	{
		printf("%i ", current_node->sorted);
		current_node = current_node->next;
	}
	printf("%i \n", current_node->sorted);
}
