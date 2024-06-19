/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:13 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 13:51:32 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	numbers_range(long *list, long sol, long max, long min)
{
	long		a;

	a = 0;
	while (a < sol)
	{
		if (list[a] >= min && list[a] <= max)
			return (1);
		a++;
	}
	return (0);
}

static t_towers	move_to_b(t_towers tower, long min, long max)
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
	long		total;
	long		current_group;
	long		*max_value;
	long		*min_value;

	tower.div = div_more_cases(tower.size);
	total = (tower.size / (long)tower.div) + !!(tower.size % (long)tower.div);
	current_group = total;
	while (current_group > 0)
	{
		if (current_group == total)
			max_value = &tower.corr[tower.size - 1];
		else
			max_value = &tower.corr[(tower.size / total) * current_group];
		min_value = &tower.corr[(tower.size / total) * (--current_group)];
		tower = move_to_b(tower, *min_value, *max_value);
		tower = move_back_to_a(tower, min_value, max_value);
	}
	while (tower.stk_a[current_group] != tower.corr[0])
	{
		rotate_down(&(tower.stk_a), tower.size);
		append_log(&tower.log, "Ra");
	}
	return (tower);
}
	/*base_groups = tower.size / (long)tower.div;
	has_remainder = (tower.size % (long)tower.div) != 0;
	amogr = base_groups + has_remainder;
	round = amogr;*/
