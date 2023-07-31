/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/31 17:50:02 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Modificar ATOL para fazer intmax/min check, ver sinais e letras
// Checkar duplicados

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

// Creates linked list and parses through argvs to check they are all correct
int	create_linked_list(char **argv, t_list **starting_node)
{
	long	value_from_argument;
	t_list	*current_node;

	value_from_argument = ft_atol(*argv);
	*starting_node = ft_lstnew(&value_from_argument, 0);
	current_node = *starting_node;
	argv++;
	while (*argv)
	{
		value_from_argument = ft_atol(*argv);
		if (check_arg_validity(*argv, value_from_argument) == 0)
		{
			if (*starting_node)
				ft_lstclear(*starting_node);
			return (0);
		}
		else
		{
			ft_lstadd_back(starting_node, ft_lstnew(&value_from_argument, 0));
			current_node = current_node->next;
		}
		argv++;
	}
	return (1);
}

int	check_duplicates(t_list *starting_node)
{
	t_list	*current_node;

	while (starting_node->next)
	{
		current_node = starting_node->next;
		while (current_node->value)
		{
			if (starting_node->value == current_node->value)
				return (0);
			if (current_node->next)
				current_node = current_node->next;
			else
				break ;
		}
		starting_node = starting_node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*starting_node;

	// If there are only 1 elements, list is already sorted
	if (argc < 3)
		return (1);
	// Checks if args are ints and if there are duplicates
	if (create_linked_list(++argv, &starting_node) == 0
		|| check_duplicates(starting_node) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// Check if it's already sorted!!!
	pseudo_sort(&starting_node, argc - 1);
	// Print list
	sort_list(&starting_node, argc - 1);
	// Delete the entirety of the linked list
	return (0);
}
