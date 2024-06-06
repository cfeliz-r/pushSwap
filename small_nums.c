/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:47 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 16:17:09 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort_two_numbers(long *list)
{
	char	*log;

	log = NULL;
	if (list[0] > list[1])
		append_log(&log, "sa");
	else
		append_log(&log, "  ");
	return (log);
}

char	*sort_three_numbers(long *list)
{
	char	*log;

	log = NULL;
	if (list[0] < list[1] && list[1] < list[2])
		append_log(&log, "  ");
	else if (list[0] < list[1])
	{
		append_log(&log, "Ra");
		if (list[0] < list[2])
			append_log(&log, "sa");
	}
	else if (list[1] > list[2])
	{
		append_log(&log, "sa");
		append_log(&log, "Ra");
	}
	else if (list[0] < list[2] && list[1] < list[2])
		append_log(&log, "sa");
	else if (list[0] > list[2] && list[1] < list[2])
		append_log(&log, "ra");
	return (log);
}

static void	five_num(t_towers *tower, long *a, long *b)
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
		rotate_down(&(*tower).a, 5);
		append_log(&(*tower).log, "Ra");
	}
	else if ((*tower).a[2] == *a || (*tower).a[2] == *b)
	{
		rotate_up(&(*tower).a, 5);
		append_log(&(*tower).log, "ra");
	}
	if ((*tower).a[1] == *a || (*tower).a[1] == *b)
	{
		rotate_up(&(*tower).a, 5);
		append_log(&(*tower).log, "ra");
	}
}

t_towers	sort_five_numbers(t_towers tower)
{
	long	a;
	long	b;

	a = 0;
	b = 0;
	if (tower.a[0] == tower.corr[2])
	{
		rotate_up(&tower.a, 5);
		append_log(&tower.log, "ra");
	}
	push_to_other_stack(&tower.a, &tower.b, 5);
	append_log(&tower.log, "pb");
	five_num(&tower, &a, &b);
	push_to_other_stack(&tower.a, &tower.b, 5);
	append_log(&tower.log, "pb");
	tower.log = ft_strjoin(tower.log, sort_three_numbers(tower.a));
	if (tower.b[0] < tower.b[1])
		append_log(&tower.log, "sb");
	append_log(&tower.log, "pa");
	append_log(&tower.log, "pa");
	if (a == tower.corr[3])
		append_log(&tower.log, "ra");
	if (a == tower.corr[3])
		append_log(&tower.log, "ra");
	return (tower);
}

t_towers	bubble_sort(t_towers tower)
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
				swap_top_two(&tower.a, tower.size);
				append_log(&tower.log, "sa");
			}
			rotate_up(&tower.a, tower.size);
			append_log(&tower.log, "ra");
			loc--;
		}
		rotate_up(&tower.a, tower.size);
		append_log(&tower.log, "ra");
		a--;
	}
	return (tower);
}
