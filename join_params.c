/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:22 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 14:50:58 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_str(char *left, char *right)
{
	char	*res;
	int		len;
	int		a;
	int		b;

	len = ft_strlen(left) + ft_strlen(right) + 1;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	a = 0;
	b = 0;
	while (left[a] && left)
	{
		res[a] = left[a];
		a++;
	}
	res[a] = ' ';
	free (left);
	while (right[b])
	{
		res[a + b + 1] = right[b];
		b++;
	}
	res[len] = '\0';
	return (res);
}

char	*join_params(int agc, char **agv)
{
	int		a;
	char	*res;

	a = 1;
	res = malloc(2);
	res[0] = ' ';
	res[1] = 0;
	while (agc > a)
	{
		res = join_str(res, agv[a]);
		a++;
	}
	return (res);
}
