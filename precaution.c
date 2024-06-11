/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precaution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:31 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/10 20:18:25 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_order(int *array, int **correct, int size)
{
	int		b;
	int		c;
	int		small;
	int		prev;

	b = 0;
	prev = -INT_MAX;
	while (b < size)
	{
		c = 0;
		small = INT_MAX;
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

int	is_ordered(int *array, int size)
{
	int		b;

	b = 1;
	while (b < size)
	{
		if (array[b] < array[b - 1])
			return (0);
		b++;
	}
	return (1);
}
