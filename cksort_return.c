/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cksort_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:53 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 16:30:25 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_towers	return_to_a_third(t_towers tower, long dir)
{
	if (dir == -1)
		rotate_up(&(tower.b), tower.size);
	else
		rotate_down(&(tower.b), tower.size);
	if (dir == -1)
		append_log(&tower.log, "rb");
	else
		append_log(&tower.log, "Rb");
	return (tower);
}

static t_towers	return_to_a_second(t_towers tower, long *min, long *max, long b)
{
	long	a;
	long	dir;

	a = -1;
	dir = 0;
	while (!dir)
	{
		a++;
		if (tower.b[a] == *min || tower.b[a] == *max)
			dir = -1;
		else if (tower.b[b - a] == *min || tower.b[b - a] == *max)
		{
			a++;
			dir = 1;
		}
	}
	while (a-- > 0)
	{
		tower = return_to_a_third(tower, dir);
	}
	return (tower);
}

t_towers	move_back_to_a(t_towers tower, long *min, long *max)
{
	long	b;

	b = 0;
	while (tower.b[b] != MT)
		b++;
	b--;
	while (tower.b[0] != MT)
	{
		tower = return_to_a_second(tower, min, max, b);
		push_to_other_stack(&(tower.b), &(tower.a), tower.size);
		append_log(&tower.log, "pa");
		if (tower.a[0] == *max)
			max--;
		else
		{
			rotate_up(&(tower.a), tower.size);
			append_log(&tower.log, "ra");
			min++;
		}
		b--;
	}
	return (tower);
}
