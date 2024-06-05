/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:22 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:55:32 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*joinstr(char *frst, char *scnd)
{
	char	*res;
	int		len;
	int		a;
	int		b;

	len = ft_strlen(frst) + ft_strlen(scnd) + 1;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	a = 0;
	b = 0;
	while (frst[a] && frst)
	{
		res[a] = frst[a];
		a++;
	}
	res[a] = ' ';
	free (frst);
	while (scnd[b])
	{
		res[a + b + 1] = scnd[b];
		b++;
	}
	res[len] = '\0';
	return (res);
}

char	*joinparams(int agc, char **agv)
{
	int		a;
	char	*res;

	a = 1;
	res = malloc(2);
	res[0] = ' ';
	res[1] = 0;
	while (agc > a)
	{
		res = joinstr(res, agv[a]);
		a++;
	}
	return (res);
}
