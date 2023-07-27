/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:13:55 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/26 20:06:48 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

// Parse through argvs to check they are all correct
int	check_args(char **argv, t_list *starting_node)
{
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*starting_node;

	// If there are only 1 elements, list is already sorted
	if (argc < 3)
		return (1);
	// Checks if args are ints and if there are duplicates
	if (check_args(argv, starting_node) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// Sort values
	// Delete the entirety of the linked list
	return (0);
}
