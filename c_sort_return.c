/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sort_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:53 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 13:47:40 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_towers	return_to_a_third(t_towers tower, long dir)
{
	if (dir == -1)
		rotate_up(&(tower.stk_b), tower.size);
	else
		rotate_down(&(tower.stk_b), tower.size);
	if (dir == -1)
		append_log(&tower.log, "rb");
	else
		append_log(&tower.log, "Rb");
	return (tower);
}

static t_towers	return_to_a_second(t_towers tower, long *min, long *max, long b)
{
	long		i;
	long		dir;

	i = -1;
	dir = 0;
	while (!dir)
	{
		i++;
		if (tower.stk_b[i] == *min || tower.stk_b[i] == *max)
			dir = -1;
		else if (tower.stk_b[b - i] == *min || tower.stk_b[b - i] == *max)
		{
			i++;
			dir = 1;
		}
	}
	while (i-- > 0)
	{
		tower = return_to_a_third(tower, dir);
	}
	return (tower);
}

t_towers	move_back_to_a(t_towers tower, long *min, long *max)
{
	long		i;

	i = 0;
	while (tower.stk_b[i] != REF)
		i++;
	i--;
	while (tower.stk_b[0] != REF)
	{
		tower = return_to_a_second(tower, min, max, i);
		push_to_other_stack(&(tower.stk_b), &(tower.stk_a), tower.size);
		append_log(&tower.log, "pa");
		if (tower.stk_a[0] == *max)
			max--;
		else
		{
			rotate_up(&(tower.stk_a), tower.size);
			append_log(&tower.log, "ra");
			min++;
		}
		i--;
	}
	return (tower);
}
