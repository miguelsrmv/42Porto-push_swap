/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:09:26 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 11:24:39 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

void	print_list_order_organized(t_list *starting_node, char c, int length)
{
	t_list	*current_node;

	current_node = starting_node;
	printf("\n______________________________________STACK %c_________________________________________\n", c-32);
	printf("Value\t\t\tAddress\t\t\tPrevious\t\tNext\n");
	while (length--)
	{
		printf("%i\t\t\t%p\t\t%p%s\t%p\n", current_node->value, &(current_node->value), current_node->prev, print_tab_calc(current_node->prev), current_node->next);
		current_node = current_node->next;
	}
	printf("\n");
}

char	*print_tab_calc(t_list *prev)
{
	if (prev == NULL)
		return ("\t\t");
	else
		return ("\t");
}

void	print_instruction(char *instruction, char stack)
{
	int	i;

	i = 0;
	while (instruction[i])
		i++;
	write(1, instruction, i);
	write(1, &stack, 1);
	write(1, "\n", 1);
}
