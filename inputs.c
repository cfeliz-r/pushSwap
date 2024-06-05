/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:07 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 12:26:10 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	countandcheckbs(char *str, long n)
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
				errmsg();
		}
		else if (str[a])
			errmsg();
		while (str[a] == ' ' && str[a])
			a++;
	}
	return (n);
}

static t_towers	reservememory(long n)
{
	long		a;
	t_towers	tower;

	a = 0;
	tower.size = n;
	tower.a = malloc(sizeof(long) * n);
	tower.b = malloc(sizeof(long) * n);
	tower.corr = malloc(sizeof(long) * n);
	if (!tower.a || !tower.b || !tower.corr)
		exit(0);
	while (a < n)
	{
		tower.a[a] = MT;
		tower.b[a] = MT;
		tower.corr[a] = MT;
		a++;
	}
	return (tower);
}

static t_towers	chartolong(t_towers tower, char *str, long index)
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
				errmsg();
		}
		tower.a[index++] = n * ((neg * -2) + 1);
	}
	return (tower);
}

void	checkfordupes(long *list, long size)
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
				errmsg();
			b++;
		}
		a++;
	}
}

t_towers	organizestruct(int agc, char **agv)
{
	char		*str;
	t_towers	tower;
	long		len;

	len = 0;
	if (agc < 2)
		errmsg();
	str = joinparams(agc, agv);
	len = countandcheckbs(str, 0);
	if (!len)
		errmsg();
	tower = reservememory(len);
	tower = chartolong(tower, str, 0);
	checkfordupes(tower.a, tower.size);
	tower.log = NULL;
	tower.div = 0;
	free (str);
	return (tower);
}
