/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:51 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/11 17:08:39 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *str, t_towers *tower)
{
	if (str)
		free(str);
	if (tower)
		free_stuff(tower);
	ft_printf("Error\n");
	exit(0);
}

void	free_stuff(t_towers *tower)
{
	if (tower)
	{
		if (tower-> stk_a)
			free(tower-> stk_a);
		if (tower-> stk_b)
			free(tower-> stk_b);
		if (tower-> corr)
			free(tower-> corr);
		if (tower-> log)
			free(tower-> log);
	}
}

static int	div_more_cases(int size)
{
	if (size == 500)
		return (85);
	else if (size == 100)
		return (35);
	else if (size < 20)
		return (5);
	else
		return (10);
}

int	main(int argc, char **argv)
{
	t_towers	tower;

	tower = initialize_struct(argc, argv);
	if (is_ordered(tower.stk_a, tower.size))
	{
		free_stuff(&tower);
		return (0);
	}
	correct_order(tower.stk_a, &tower.corr, tower.size);
	if (tower.size == 2)
		tower.log = sort_two_numbers(tower.stk_a);
	else if (tower.size == 3)
		tower.log = sort_three_numbers(tower.stk_a);
	else if (tower.size == 5)
		tower = sort_five_numbers(tower);
	else if (tower.size < 20)
		tower = bubble_sort(tower);
	else
		tower.div = div_more_cases(tower.size);
	if (tower.div != 0)
		tower = c_sort(tower);
	optimize_log(&tower.log);
	display_log(tower.log);
	free_stuff(&tower);
	return (0);
}
