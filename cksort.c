/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cksort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:13 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:07:25 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numsinrange(long *list, long sol, long max, long min)
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

static t_towers	movetob(t_towers tower, long min, long max)
{
	while (numsinrange(tower.a, tower.size, max, min))
	{
		if (tower.a[0] >= min && tower.a[0] <= max)
		{
			px(&tower.a, &tower.b, tower.size);
			addlog(&tower.log, "pb");
		}
		else
		{
			rx(&tower.a, tower.size);
			addlog(&tower.log, "ra");
		}	
	}
	return (tower);
}

t_towers	chunksort(t_towers tower)
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
		tower = movetob(tower, *min, *max);
		tower = returntoa(tower, min, max);
	}
	while (tower.a[round] != tower.corr[0])
	{
		rrx(&(tower.a), tower.size);
		addlog(&tower.log, "Ra");
	}
	return (tower);
}
