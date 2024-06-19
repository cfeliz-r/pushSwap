/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:51 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/20 01:33:21 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *str, t_towers *tower)
{
	if (str)
		free(str);
	if (tower)
		free_stuff(tower);
	ft_prlongf("Error\n");
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

long	div_more_cases(long size)
{
	if (size == 500)
		return (85);
	else if (size == 100)
		return (40);
	else if(size == 4 || size == 5)
		return (2);
	else if(size >= 6 && size <= 15)
		return (3);
	else if(size > 15 && size <= 50)
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
	else if (tower.size == 6)
		tower = sort_five_numbers(tower);
	else
		tower = c_sort(tower);
	display_log(tower.log);
	free_stuff(&tower);
	return (0);
}
