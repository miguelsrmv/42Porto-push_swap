/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_create_linked_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:10:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/16 14:36:43 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

// Verifies if given char is a digit
int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Transforms arguments into longs
long	ft_atol(char *argument)
{
	int			sign;
	long		n;

	n = 0;
	sign = 1;
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

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Checks if all arguments are digits with one + or - before
int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(*argv) == 0)
		return (0);
	while (argv[i])
	{
		if ((argv[i][j] == '+' || argv[i][j] == '-') && argv[i][j + 1])
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

// Checks for duplicate values on linked list
int	check_duplicates(t_list *starting_node)
{
	t_list	*current_node;
	t_list	*copy_node;

	copy_node = starting_node;
	while (copy_node->next)
	{
		current_node = copy_node->next;
		while (current_node)
		{
			if (copy_node->value == current_node->value)
			{
				ft_lstclear(starting_node);
				return (0);
			}
			if (current_node->next)
				current_node = current_node->next;
			else
				break ;
		}
		copy_node = copy_node->next;
	}
	return (1);
}
