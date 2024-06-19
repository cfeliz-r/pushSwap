/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precaution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:31 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 13:49:30 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_order(long *array, long **correct, long size)
{
	long		b;
	long		c;
	long		small;
	long		prev;

	b = 0;
	prev = -REF;
	while (b < size)
	{
		c = 0;
		small = REF;
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

long	is_ordered(long *array, long size)
{
	long		b;

	b = 1;
	while (b < size)
	{
		if (array[b] < array[b - 1])
			return (0);
		b++;
	}
	return (1);
}
