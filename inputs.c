/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:07 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/08 00:51:15 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_and_checkbs(char *str, long n)
{
	long		a;

	a = 0;
	while (str[a])
	{
		while (str[a] == ' ')
			a++;
		if (str[a] == '-' || str[a] == '+')
			a++;
		if (ft_isdigit(str[a]))
		{
			while (ft_isdigit(str[a]))
				a++;
			n++;
			if (str[a] != ' ' && str[a])
				print_error(str, NULL);
		}
		else if (str[a])
			print_error(str, NULL);
		while (str[a] == ' ' && str[a])
			a++;
	}
	return (n);
}

static t_towers	reserve_memory(long n)
{
	long		a;
	t_towers	tower;

	a = 0;
	tower.size = n;
	tower.a = malloc(sizeof(long) * n);
	tower.b = malloc(sizeof(long) * n);
	tower.corr = malloc(sizeof(long) * n);
	if (!tower.a || !tower.b || !tower.corr)
		print_error(NULL, &tower);
	while (a < n)
	{
		tower.a[a] = MT;
		tower.b[a] = MT;
		tower.corr[a] = MT;
		a++;
	}
	return (tower);
}

static t_towers	char_to_long(t_towers tower, char *str, long index)
{
	long	n;
	int		a;
	int		neg;

	a = 0;
	while (str[a])
	{
		n = 0;
		neg = 0;
		while ((str[a] == ' ' || str[a] == '+' || str[a] == '-') && str[a])
			a++;
		if (str[a - 1] == '-')
			neg = 1;
		if (!str[a])
			break ;
		while (ft_isdigit(str[a]))
		{
			n = n * 10 + str[a++] - '0';
			if (n > (long)2147483647 + (long)neg)
				print_error(str, &tower);
		}
		tower.a[index++] = n * ((neg * -2) + 1);
	}
	return (tower);
}

static void	check_for_dupes(long *list, long size)
{
	long	a;
	long	b;

	a = 0;
	b = 1;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (list[a] == list[b])
				print_error(NULL, NULL);
			b++;
		}
		a++;
	}
}

t_towers	initialize_struct(int agc, char **agv)
{
	char		*str;
	t_towers	tower;
	long		len;

	len = 0;
	if (agc < 2)
		print_error(NULL, NULL);
	str = join_params(agc, agv);
	len = count_and_checkbs(str, 0);
	if (!len)
		print_error(str, NULL);
	tower = reserve_memory(len);
	tower = char_to_long(tower, str, 0);
	check_for_dupes(tower.a, tower.size);
	tower.log = NULL;
	tower.div = 0;
	free (str);
	return (tower);
}
