/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precaution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:31 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:54:58 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	docorrectorder(long *a, long **corr, long size)
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
			if (a[c] < small && a[c] > prev)
				small = a[c];
			c++;
		}
		corr[0][b] = small;
		prev = small;
		b++;
	}
}

int	checkorder(long *a, long size)
{
	long	b;

	b = 1;
	if (a[size - 1] == MT)
		return (0);
	while (b < size)
	{
		if (a[b] < a[b - 1])
			return (0);
		b++;
	}
	return (1);
}
