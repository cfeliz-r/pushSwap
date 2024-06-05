/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:47 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:54:40 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*twonums(long *list)
{
	char	*log;

	log = NULL;
	if (list[0] > list[1])
		addlog(&log, "sa");
	else
		addlog(&log, "  ");
	return (log);
}

char	*threenums(long *list)
{
	char	*log;

	log = NULL;
	if (list[0] < list[1] && list[1] < list[2])
		addlog(&log, "  ");
	else if (list[0] < list[1])
	{
		addlog(&log, "Ra");
		if (list[0] < list[2])
			addlog(&log, "sa");
	}
	else if (list[1] > list[2])
	{
		addlog(&log, "sa");
		addlog(&log, "Ra");
	}
	else if (list[0] < list[2] && list[1] < list[2])
		addlog(&log, "sa");
	else if (list[0] > list[2] && list[1] < list[2])
		addlog(&log, "ra");
	return (log);
}

static void	fivenumsifs(t_towers *tower, long *a, long *b)
{
	if ((*tower).b[0] == (*tower).corr[0] || (*tower).b[0] == (*tower).corr[1])
	{
		*a = (*tower).corr[0];
		*b = (*tower).corr[1];
	}
	if ((*tower).b[0] == (*tower).corr[3] || (*tower).b[0] == (*tower).corr[4])
	{
		*a = (*tower).corr[3];
		*b = (*tower).corr[4];
	}
	if ((*tower).a[3] == *a || (*tower).a[3] == *b)
	{
		rrx(&(*tower).a, 5);
		addlog(&(*tower).log, "Ra");
	}
	else if ((*tower).a[2] == *a || (*tower).a[2] == *b)
	{
		rx(&(*tower).a, 5);
		addlog(&(*tower).log, "ra");
	}
	if ((*tower).a[1] == *a || (*tower).a[1] == *b)
	{
		rx(&(*tower).a, 5);
		addlog(&(*tower).log, "ra");
	}
}

t_towers	fivenums(t_towers tower)
{
	long	a;
	long	b;

	a = 0;
	b = 0;
	if (tower.a[0] == tower.corr[2])
	{
		rx(&tower.a, 5);
		addlog(&tower.log, "ra");
	}
	px(&tower.a, &tower.b, 5);
	addlog(&tower.log, "pb");
	fivenumsifs(&tower, &a, &b);
	px(&tower.a, &tower.b, 5);
	addlog(&tower.log, "pb");
	tower.log = ft_strjoin(tower.log, threenums(tower.a));
	if (tower.b[0] < tower.b[1])
		addlog(&tower.log, "sb");
	addlog(&tower.log, "pa");
	addlog(&tower.log, "pa");
	if (a == tower.corr[3])
		addlog(&tower.log, "ra");
	if (a == tower.corr[3])
		addlog(&tower.log, "ra");
	return (tower);
}

t_towers	bubblesort(t_towers tower)
{
	long	a;
	long	loc;

	a = tower.size;
	while (a)
	{
		loc = tower.size;
		while (loc - 1)
		{
			if (tower.a[0] > tower.a[1])
			{
				sx(&tower.a, tower.size);
				addlog(&tower.log, "sa");
			}
			rx(&tower.a, tower.size);
			addlog(&tower.log, "ra");
			loc--;
		}
		rx(&tower.a, tower.size);
		addlog(&tower.log, "ra");
		a--;
	}
	return (tower);
}
