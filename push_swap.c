/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:51 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/07 01:39:38 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

static void	free_stuff(t_towers *tower)
{
	free((*tower).a);
	free((*tower).b);
	free((*tower).corr);
	free((*tower).log);
}

static int	div_more_cases(long size)
{
	if (size > 300 && size <= 500)
		return (90);
	else if (size > 50 && size <= 100)
		return (40);
	else if (size >= 30 && size < 50)
		return (20);
	else
		return (10);
}
int	main(int argc, char **argv)
{
	t_towers	tower;

	tower = initialize_struct(argc, argv);
	if (is_ordered(tower.a, tower.size))
		return (0);
	correct_order(tower.a, &tower.corr, tower.size);
	if (tower.size == 2)
		tower.log = sort_two_numbers(tower.a);
	else if (tower.size == 3)
		tower.log = sort_three_numbers(tower.a);
	else if (tower.size <= 5 && tower.size >= 4)
		tower = sort_five_numbers(tower);
	else if (tower.size < 50)
		tower = bubble_sort(tower);
	else
		tower.div = div_more_cases(tower.size);
	if(tower.div != 0)
		tower = c_sort(tower);
	optimize_log(&tower.log);
	display_log(tower.log);
	free_stuff(&tower);
	return (0);
}
