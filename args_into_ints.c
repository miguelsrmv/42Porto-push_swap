/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_into_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:10:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/31 16:02:31 by mde-sa--         ###   ########.fr       */
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

// Gets minimum value from list that hasn't been picked before
t_list	*get_min_from_list(t_list *starting_node, int list_length)
{
	t_list	*current_node;
	t_list	*min_node;

	current_node = starting_node;
	while (current_node->sorted >= 0)
		current_node = current_node->next;
/* 	if (!current_node->next && current_node->sorted)
		return (NULL); */
	min_node = current_node;
	while (list_length--)
	{
		if (current_node->value < min_node->value && current_node->sorted < 0)
			min_node = current_node;
		if (current_node->next)
			current_node = current_node->next;
	}
	return (min_node);
}

// Attributes hypothetical position to node->sorted, in case list was sorted
void	pseudo_sort(t_list **starting_node, int list_length)
{
	t_list	*min_node;
	int		order_number;

	order_number = 0;
	while (order_number < list_length)
	{
		min_node = get_min_from_list(*starting_node, list_length);
		min_node->sorted = order_number;
		min_node->binary_value = int_to_binary(order_number);
		order_number++;
	}
}
