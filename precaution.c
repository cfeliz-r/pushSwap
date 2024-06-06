/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precaution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:31 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 15:55:04 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_order(long *array, long **correct, long size)
{
	long	b;
	long	c;
	long	small;
	long	prev;

	b = 0;
	prev = -MT;
	while (b < size)
	{
		c = 0;
		small = MT;
		while (c < size)
		{
			if (array[c] < small && array[c] > prev)
				small = array[c];
			c++;
		}
		correct[0][b] = small;
		prev = small;
		b++;
	}
}

int	is_ordered(long *array, long size)
{
	long	b;

	b = 1;
	if (array[size - 1] == MT)
		return (0);
	while (b < size)
	{
		if (array[b] < array[b - 1])
			return (0);
		b++;
	}
	return (1);
}
