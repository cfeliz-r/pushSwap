/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:13 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/11 16:58:48 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numbers_range(int *list, int sol, int max, int min)
{
	int		a;

	a = 0;
	while (a < sol)
	{
		if (list[a] >= min && list[a] <= max)
			return (1);
		a++;
	}
	return (0);
}

static t_towers	move_to_b(t_towers tower, int min, int max)
{
	while (numbers_range(tower.stk_a, tower.size, max, min))
	{
		if (tower.stk_a[0] >= min && tower.stk_a[0] <= max)
		{
			push_to_other_stack(&tower.stk_a, &tower.stk_b, tower.size);
			append_log(&tower.log, "pb");
		}
		else
		{
			rotate_up(&tower.stk_a, tower.size);
			append_log(&tower.log, "ra");
		}
	}
	return (tower);
}

t_towers	c_sort(t_towers tower)
{
	int		total;
	int		current;
	int		*max;
	int		*min;

	total = (tower.size / (int)tower.div) + !!(tower.size % (int)tower.div);
	current = total;
	while (current > 0)
	{
		if (current == total)
			max = &tower.corr[tower.size - 1];
		else
			max = &tower.corr[(tower.size / total) * current];
		min = &tower.corr[(tower.size / total) * (--current)];
		tower = move_to_b(tower, *min, *max);
		tower = move_back_to_a(tower, min, max);
	}
	while (tower.stk_a[current] != tower.corr[0])
	{
		rotate_down(&(tower.stk_a), tower.size);
		append_log(&tower.log, "Ra");
	}
	return (tower);
}
	/*base_groups = tower.size / (int)tower.div;
	has_remainder = (tower.size % (int)tower.div) != 0;
	amogr = base_groups + has_remainder;
	round = amogr;*/
