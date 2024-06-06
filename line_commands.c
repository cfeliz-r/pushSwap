/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:07 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 16:25:19 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(long **stack, long size)
{
	long	aux;

	aux = 0;
	if (size >= 2)
	{
		aux = stack[0][0];
		stack[0][0] = stack[0][1];
		stack[0][1] = aux;
	}
}

void	push_to_other_stack(long **src, long **dest, long size)
{
	if (dest[0][size - 1] == MT && src[0][0] != MT)
	{
		shift_down(dest, size);
		dest[0][0] = src[0][0];
		shift_up(src, size);
	}
}

void	rotate_up(long **stack, long size)
{
	long	aux;
	long	a;

	a = 0;
	if (size >= 2)
	{
		aux = stack[0][0];
		shift_up(stack, size);
		while (stack[0][a] != MT && a < size)
			a++;
		stack[0][a] = aux;
	}
}

void	rotate_down(long **stack, long size)
{
	long	aux;
	long	a;

	a = 0;
	if (size >= 2)
	{
		while (a + 1 < size && (*stack)[a] != MT)
			a++;
		if ((*stack)[a] == MT)
			a--;
		aux = stack[0][a];
		stack[0][a] = MT;
		shift_down(stack, size);
		stack[0][0] = aux;
	}
}
