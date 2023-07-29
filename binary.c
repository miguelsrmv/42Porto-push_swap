/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:36:33 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/07/29 11:31:34 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Converts int to its binary representation as an int
int	int_to_binary(int number)
{
	int	binary_result;
	int	i;

	binary_result = 0;
	i = 1;
	while (number > 0)
	{
		binary_result += (number % 2) * i;
		number = number / 2;
		i *= 10;
	}
	return (binary_result);
}

// Equivalent function
int	int_to_binary_two(int number)
{
	int	binary_result;
	int	bit_position;

	binary_result = 0;
	bit_position = 1;

	while (number > 0)
	{
		binary_result += (number & 1) * bit_position;
		number = number >> 1;
		bit_position *= 10;
	}
	return (binary_result);
}
