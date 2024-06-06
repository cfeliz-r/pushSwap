/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:33 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 16:40:11 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_log(char **log, char *action)
{
	char	*newlog;
	long	b;

	b = 0;
	if (!(*log))
	{
		(*log) = ft_strdup(action);
		return ;
	}
	newlog = malloc(ft_strlen(*log) + 3);
	while ((*log)[b])
	{
		newlog[b] = (*log)[b];
		b++;
	}
	newlog[b++] = action[0];
	newlog[b++] = action[1];
	newlog[b] = 0;
	free (*log);
	*log = newlog;
}

void	display_log(char *log)
{
	long	a;

	a = 0;
	while (log[a])
	{
		while (log[a] == ' ')
			a++;
		if (log[a] == 'R')
			ft_printf("rr");
		else
			ft_printf("%c", log[a]);
		a++;
		if (log[a] == 'R')
			ft_printf("r");
		else
			ft_printf("%c", log[a]);
		ft_printf("\n");
		a++;
	}
}

static int	optimize_log_two(char **log, long *a, long *b)
{
	if ((*log)[*b] == 'p' || (*log)[*b + 1] == 's' || (*log)[*b + 1] == 'r')
		return (0);
	else if ((*log)[*b + 1] == (*log)[*a + 1])
		*b += 2;
	else if ((*log)[*b] != (*log)[*a])
		return (0);
	else
	{
		(*log)[*a + 1] = (*log)[*a];
		(*log)[*b] = ' ';
		(*log)[*b + 1] = ' ';
	}
	return (1);
}

void	optimize_log(char **log)
{
	long	a;
	long	b;

	a = 0;
	b = a + 2;
	while ((*log)[a])
	{
		if ((*log)[a] == 'p' || (*log)[a + 1] == 's' || (*log)[a + 1] == 'r')
			a = a + 2;
		else
		{
			b = a + 2;
			while ((*log)[b])
			{
				if (!optimize_log_two(log, &a, &b))
					break ;
			}
		}
		a += 2;
	}
}

int	get_log_count(char *log)
{
	long	a;
	long	res;

	a = 0;
	res = 0;
	while (log[a])
	{
		while (log[a] == ' ')
			a++;
		a += 2;
		res++;
	}
	return (res);
}
