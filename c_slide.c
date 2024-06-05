/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_slide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:20 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:09:11 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	slideup(long **list, long size)
{
	long	a;

	a = 1;
	if (size > 1)
	{
		while (a < size && list[0][a] != MT)
		{
			list[0][a - 1] = list[0][a];
			a++;
		}
		list[0][a - 1] = MT;
	}
}

void	slidedwn(long **list, long size)
{
	long	a;

	a = size - 1;
	if (size > 0)
	{
		while (a > 0)
		{
			list[0][a] = list[0][a - 1];
			a--;
		}
		list[0][0] = MT;
	}
}
