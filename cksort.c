/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cksort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:13 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/08 00:59:51 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numbers_range(long *list, long sol, long max, long min)
{
	long	a;

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
	while (numbers_range(tower.a, tower.size, max, min))
	{
		if (tower.a[0] >= min && tower.a[0] <= max)
		{
			push_to_other_stack(&tower.a, &tower.b, tower.size);
			append_log(&tower.log, "pb");
		}
		else
		{
			rotate_up(&tower.a, tower.size);
			append_log(&tower.log, "ra");
		}
	}
	return (tower);
}

t_towers	c_sort(t_towers tower)
{
	long	amogr;
	long	round;
	long	*max;
	long	*min;

	amogr = (tower.size / (long)tower.div) + !!(tower.size % (long)tower.div);
	round = amogr;
	while (round > 0)
	{
		if (round == amogr)
			max = &tower.corr[tower.size - 1];
		else
			max = &tower.corr[(tower.size / amogr) * round];
		min = &tower.corr[(tower.size / amogr) * (--round)];
		tower = move_to_b(tower, *min, *max);
		tower = move_back_to_a(tower, min, max);
	}
	while (tower.a[round] != tower.corr[0])
	{
		rotate_down(&(tower.a), tower.size);
		append_log(&tower.log, "Ra");
	}
	return (tower);
}
