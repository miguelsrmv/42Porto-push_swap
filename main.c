/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/27 12:25:12 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Modificar ATOL para fazer intmax/min check
// Checkar duplicados

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

// Transforms arguments into longs
int	ft_atol(char *argument)
{
	int		sign;
	int		n;

	n = 0;
	sign = 1;
	while ((*argument > 8 && *argument < 14) || *argument == 32)
		argument++;
	if (*argument == '-' || *argument == '+')
	{
		if (*argument == '-')
			sign = -sign;
		argument++;
	}
	while (*argument >= '0' && *argument <= '9')
	{
		n = n * 10 + *argument - '0';
		argument++;
	}
	return (n * sign);
}

// Creates linked list and parses through argvs to check they are all correct
int	create_linked_list(char **argv, t_list **starting_node)
{
	int		i;
	int		value_from_argument;
	t_list *current_node;

	i = 0;
	while (argv[++i])
	{
		value_from_argument = ft_atol(argv[i]);
		if (!value_from_argument)
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

void print_list(t_list *starting_node)
{
 	t_list *current_node;

	current_node = starting_node;
	while (current_node->next)
	{
		printf("%i ", current_node->value);
		current_node = current_node->next;
	}
	printf("%i ", current_node->value);
	printf("\n");
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
