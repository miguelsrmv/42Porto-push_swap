/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/28 19:33:50 by mde-sa--         ###   ########.fr       */
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

void	print_list_order_organized(t_list *starting_node)
{
	t_list	*current_node;
	int		i;

	current_node = starting_node;
	i = 0;

	printf("Value\t\tIndex\t\tBinary Index\n");
	while (current_node->next)
	{
		printf("%i\t\t%i\t\t%i\n", current_node->value, current_node->sorted, current_node->binary_value);
		current_node = current_node->next;
	}
	printf("%i\t\t%i\t\t%i\n", current_node->value, current_node->sorted, current_node->binary_value);
}
