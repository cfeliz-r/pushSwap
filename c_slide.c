/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_slide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:20 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/08 16:13:02 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up(int **list, int size)
{
	int		a;

	a = 1;
	if (size > 1)
	{
		while (a < size && list[0][a] != INT_MAX)
		{
			list[0][a - 1] = list[0][a];
			a++;
		}
		list[0][a - 1] = INT_MAX;
	}
}

void	shift_down(int **list, int size)
{
	int		a;

	a = size - 1;
	if (size > 0)
	{
		while (a > 0)
		{
			list[0][a] = list[0][a - 1];
			a--;
		}
		list[0][0] = INT_MAX;
	}
}
