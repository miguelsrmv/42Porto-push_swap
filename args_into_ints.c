/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_into_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:10:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/27 16:15:52 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include <limits.h>

//Verifies if given char is a digit
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

int	check_arg_validity(char *argument, long value)
{
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	while (*argument)
	{
		if (ft_isdigit(*argument) == 0)
			return (0);
		argument++;
	}
	return (1);
}
