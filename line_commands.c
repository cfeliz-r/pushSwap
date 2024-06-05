/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:07 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:55:26 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(long **list, long size)
{
	long	aux;

	aux = 0;
	if (size >= 2)
	{
		aux = list[0][0];
		list[0][0] = list[0][1];
		list[0][1] = aux;
	}
}

void	px(long **dep, long **arr, long size)
{
	if (arr[0][size - 1] == MT && dep[0][0] != MT)
	{
		slidedwn(arr, size);
		arr[0][0] = dep[0][0];
		slideup(dep, size);
	}
}

void	rx(long **list, long size)
{
	long	aux;
	long	a;

	a = 0;
	if (size >= 2)
	{
		aux = list[0][0];
		slideup(list, size);
		while (list[0][a] != MT && a < size)
			a++;
		list[0][a] = aux;
	}
}

void	rrx(long **list, long size)
{
	long	aux;
	long	a;

	a = 0;
	if (size >= 2)
	{
		while (a + 1 < size && (*list)[a] != MT)
			a++;
		if ((*list)[a] == MT)
			a--;
		aux = list[0][a];
		list[0][a] = MT;
		slidedwn(list, size);
		list[0][0] = aux;
	}
}
