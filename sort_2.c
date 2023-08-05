/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:17:58 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/05 19:50:43 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_3(t_ptr **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->next->value;
	b = (*stack)->next->next->value;
	c = (*stack)->next->next->next->value;
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_stack(stack);
		swap_stack(stack);
	}
	else if (a < b && b < c && a > c)
		reverse_rotate_stack(stack);
	else if (a > b && b < c && a < c)
		swap_stack(stack);
	else if (a > b && b < c && a > c)
		rotate_stack(stack);
	else
	{
		swap_stack(stack);
		reverse_rotate_stack(stack);
	}
}
