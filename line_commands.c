/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:07 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/08 18:12:30 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(int **stack, int size)
{
	int		aux;

	aux = 0;
	if (size >= 2)
	{
		aux = stack[0][0];
		stack[0][0] = stack[0][1];
		stack[0][1] = aux;
	}
}

void	push_to_other_stack(int **src, int **dest, int size)
{
	if (dest[0][size - 1] == INT_MAX && src[0][0] != INT_MAX)
	{
		shift_down(dest, size);
		dest[0][0] = src[0][0];
		shift_up(src, size);
	}
}

void	rotate_up(int **stack, int size)
{
	int		aux;
	int		a;

	a = 0;
	if (size >= 2)
	{
		aux = stack[0][0];
		shift_up(stack, size);
		while (stack[0][a] != INT_MAX && a < size)
			a++;
		stack[0][a] = aux;
	}
}

void	rotate_down(int **stack, int size)
{
	int		aux;
	int		a;

	a = 0;
	if (size >= 2)
	{
		while (a + 1 < size && (*stack)[a] != INT_MAX)
			a++;
		if ((*stack)[a] == INT_MAX)
			a--;
		aux = stack[0][a];
		stack[0][a] = INT_MAX;
		shift_down(stack, size);
		stack[0][0] = aux;
	}
}
