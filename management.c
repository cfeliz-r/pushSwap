/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:33 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/11 17:04:47 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_log(char *log)
{
	int		i;

	i = 0;
	while (log[i])
	{
		while (log[i] == ' ')
			i++;
		if (log[i] == 'R')
			ft_printf("rr");
		else
			ft_printf("%c", log[i]);
		i++;
		if (log[i] == 'R')
			ft_printf("r");
		else
			ft_printf("%c", log[i]);
		ft_printf("\n");
		i++;
	}
}

static int	optimize_log_two(char **log, int *i, int *j)
{
	if ((*log)[*j] == 'p' || (*log)[*j + 1] == 's' || (*log)[*j + 1] == 'r')
		return (0);
	else if ((*log)[*j + 1] == (*log)[*i + 1])
		*j += 2;
	else if ((*log)[*j] != (*log)[*i])
		return (0);
	else
	{
		(*log)[*i + 1] = (*log)[*i];
		(*log)[*j] = ' ';
		(*log)[*j + 1] = ' ';
	}
	return (1);
}

void	optimize_log(char **log)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	while ((*log)[i])
	{
		if ((*log)[i] == 'p' || (*log)[i + 1] == 's' || (*log)[i + 1] == 'r')
			i = i + 2;
		else
		{
			j = i + 2;
			while ((*log)[j])
			{
				if (!optimize_log_two(log, &i, &j))
					break ;
			}
		}
		i += 2;
	}
}

int	get_log_count(char *log)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (log[i])
	{
		while (log[i] == ' ')
			i++;
		i += 2;
		res++;
	}
	return (res);
}
