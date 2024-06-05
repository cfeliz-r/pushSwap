/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:51 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:54:50 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errmsg(void)
{
	write(1, "Error ", 6);
	write(1, "\n", 1);
	exit(0);
}

static void	freestuff(t_towers *tower)
{
	free((*tower).a);
	free((*tower).b);
	free((*tower).corr);
	free((*tower).log);
}

static int	divmorecases(long size)
{
	if (size > 2000)
		return (500);
	else if (size > 1000 && size <= 2000)
		return (250);
	else if (size > 550 && size <= 1000)
		return (150);
	else if (size > 300 && size <= 550)
		return (90);
	else if (size > 100 && size <= 300)
		return (70);
	else if (size >= 50 && size <= 100)
		return (40);
	else if (size >= 30 && size < 50)
		return (20);
	else
		return (10);
}

int	main(int argc, char **argv)
{
	t_towers	tower;

	tower = organizestruct(argc, argv);
	if (checkorder(tower.a, tower.size))
		return (0);
	docorrectorder(tower.a, &tower.corr, tower.size);
	if (tower.size == 2)
		tower.log = twonums(tower.a);
	else if (tower.size == 3)
		tower.log = threenums(tower.a);
	else if (tower.size == 5)
		tower = fivenums(tower);
	else if (tower.size < 20)
		tower = bubblesort(tower);
	else
		tower.div = divmorecases(tower.size);
	if (tower.div != 0)
		tower = chunksort(tower);
	improvelog(&tower.log);
	printlog(tower.log);
	freestuff(&tower);
	return (0);
}
