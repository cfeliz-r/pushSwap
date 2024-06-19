/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:47 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/20 01:30:42 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort_two_numbers(long *list)
{
	char	*log;

	log = NULL;
	if (list[0] > list[1])
		append_log(&log, "sa");
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

static void	five_num(t_towers *tow, long *a, long *b)
{
	if ((*tow).stk_b[0] == (*tow).corr[0] || (*tow).stk_b[0] == (*tow).corr[1])
	{
		*a = (*tow).corr[0];
		*b = (*tow).corr[1];
	}
	if ((*tow).stk_b[0] == (*tow).corr[3] || (*tow).stk_b[0] == (*tow).corr[4])
	{
		*a = (*tow).corr[3];
		*b = (*tow).corr[4];
	}
	if ((*tow).stk_a[3] == *a || (*tow).stk_a[3] == *b)
	{
		rotate_down(&(*tow).stk_a, 5);
		append_log(&(*tow).log, "Ra");
	}
	else if ((*tow).stk_a[2] == *a || (*tow).stk_a[2] == *b)
	{
		rotate_up(&(*tow).stk_a, 5);
		append_log(&(*tow).log, "ra");
	}
	if ((*tow).stk_a[1] == *a || (*tow).stk_a[1] == *b)
	{
		rotate_up(&(*tow).stk_a, 5);
		append_log(&(*tow).log, "ra");
	}
}

t_towers	sort_five_numbers(t_towers tower)
{
	long		i;
	long		j;

	i = 0;
	j = 0;
	if (tower.stk_a[0] == tower.corr[2])
	{
		rotate_up(&tower.stk_a, 5);
		append_log(&tower.log, "ra");
	}
	push_to_other_stack(&tower.stk_a, &tower.stk_b, 5);
	append_log(&tower.log, "pb");
	five_num(&tower, &i, &j);
	push_to_other_stack(&tower.stk_a, &tower.stk_b, 5);
	append_log(&tower.log, "pb");
	tower.log = ft_strjoin(tower.log, sort_three_numbers(tower.stk_a));
	if (tower.stk_b[0] < tower.stk_b[1])
		append_log(&tower.log, "sb");
	append_log(&tower.log, "pa");
	append_log(&tower.log, "pa");
	if (i == tower.corr[3])
		append_log(&tower.log, "ra");
	if (i == tower.corr[3])
		append_log(&tower.log, "ra");
	return (tower);
}
