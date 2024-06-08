/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:33 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/08 17:28:52 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_log(char **log, char *action)
{
	char	*newlog;
	int		i;

	i = 0;
	if (!(*log))
	{
		(*log) = ft_strdup(action);
		return ;
	}
	newlog = malloc(ft_strlen(*log) + 3);
	while ((*log)[i])
	{
		newlog[i] = (*log)[i];
		i++;
	}
	newlog[i++] = action[0];
	newlog[i++] = action[1];
	newlog[i] = 0;
	free (*log);
	*log = newlog;
}

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

static int	optimize_log_two(char **log, int *a, int *b)
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
	int		i;
	int		j;

	i = 0;
	j = i + 2;
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
