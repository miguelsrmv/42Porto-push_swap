/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/27 14:25:41 by mde-sa--         ###   ########.fr       */
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
	int		i;
	long	value_from_argument;
	t_list *current_node;

	i = 0;
	while (argv[++i])
	{
		value_from_argument = ft_atol(argv[i]);
		if (check_arg_validity(argv[i], value_from_argument) == 0)
		{
			if (*starting_node)
				ft_lstclear(*starting_node);
			return (0);
		}
		if (i == 1)
		{
			*starting_node = ft_lstnew(&value_from_argument);
			current_node = *starting_node;
		}
		else
		{
			ft_lstadd_back(starting_node, ft_lstnew(&value_from_argument));
			current_node = current_node->next;
		}
	}
	return (1);
}

int check_duplicates(t_list *starting_node)
{
	t_list *current_node;

	while (starting_node->next)
	{
		current_node = starting_node->next;
		while(current_node->value)
		{
			if (starting_node->value == current_node->value)
				return (1);
			current_node = current_node->next;
		}
		starting_node = starting_node->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*starting_node;

	// If there are only 1 elements, list is already sorted
	if (argc < 3)
		return (1);
	
	// Checks if args are ints and if there are duplicates
	if (create_linked_list(argv, &starting_node) == 0 || check_duplicates(starting_node) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_list(starting_node);
	// Sort values
	// Delete the entirety of the linked list
	return (0);
}
