/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:07 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/11 17:03:34 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_and_checkbs(char *str, int n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
			n++;
			if (str[i] != ' ' && str[i])
				print_error(str, NULL);
		}
		else if (str[i])
			print_error(str, NULL);
		while (str[i] == ' ' && str[i])
			i++;
	}
	return (n);
}

static t_towers	reserve_memory(int n)
{
	int			i;
	t_towers	tower;

	i = 0;
	tower.size = n;
	tower.stk_a = malloc(sizeof(int) * n);
	tower.stk_b = malloc(sizeof(int) * n);
	tower.corr = malloc(sizeof(int) * n);
	if (!tower.stk_a || !tower.stk_b || !tower.corr)
		print_error(NULL, &tower);
	while (i < n)
	{
		tower.stk_a[i] = INT_MAX;
		tower.stk_b[i] = INT_MAX;
		tower.corr[i] = INT_MAX;
		i++;
	}
	return (tower);
}

static t_towers	char_to_int(t_towers tower, char *str, int index)
{
	long	n;
	int		i;
	int		neg;

	i = 0;
	while (str[i])
	{
		n = 0;
		neg = 0;
		while ((str[i] == ' ' || str[i] == '+' || str[i] == '-') && str[i])
			i++;
		if (str[i - 1] == '-')
			neg = 1;
		if (!str[i])
			break ;
		while (ft_isdigit(str[i]))
		{
			n = n * 10 + str[i++] - '0';
			if (n > INT_MAX)
				print_error(str, NULL);
		}
		tower.stk_a[index++] = n * ((neg * -2) + 1);
	}
	return (tower);
}

static void	check_for_duplicates(int *list, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j])
				print_error(NULL, NULL);
			j++;
		}
		i++;
	}
}

t_towers	initialize_struct(int agc, char **agv)
{
	char		*str;
	t_towers	tower;
	int			len;

	len = 0;
	if (agc < 2)
		exit(0);
	str = join_params(agc, agv);
	len = count_and_checkbs(str, 0);
	tower = reserve_memory(len);
	tower = char_to_int(tower, str, 0);
	check_for_duplicates(tower.stk_a, tower.size);
	tower.log = NULL;
	tower.div = 0;
	free(str);
	return (tower);
}
