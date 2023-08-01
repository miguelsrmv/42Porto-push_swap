/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_value_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:10:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/01 09:39:32 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include <limits.h>

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

// Checks if numbers are ints or have non-digits
int	check_arg_validity(char *argument, long value)
{
	int	i;

	i = 0;
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (value < 0)
		i++;
	while (argument[i])
	{
		if (ft_isdigit(argument[i]) == 0)
			return (0);
		i++;
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






