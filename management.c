/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:26:33 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 21:39:59 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addlog(char **log, char *a)
{
	char	*newlog;
	long	b;

	b = 0;
	if (!(*log))
	{
		(*log) = ft_strdup(a);
		return ;
	}
	newlog = malloc(ft_strlen(*log) + 3);
	while ((*log)[b])
	{
		newlog[b] = (*log)[b];
		b++;
	}
	newlog[b++] = a[0];
	newlog[b++] = a[1];
	newlog[b] = 0;
	free (*log);
	*log = newlog;
}

void	printlog(char *log)
{
	long	a;

	a = 0;
	while (log[a])
	{
		while (log[a] == ' ')
			a++;
		if (log[a] == 'R')
			write(1, "rr", 2);
		else
			write(1, &log[a], 1);
		a++;
		if (log[a] == 'R')
			write(1, "r", 2);
		else
			write(1, &log[a], 1);
		write(1, "\n", 1);
		a++;
	}
}

/*static int	improvelogtwo(char **log, long *a, long *b)
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
} Si todo va bien se elimina ttambien*/

/*void	improvelog(char **log)
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
				if (!improvelogtwo(log, &a, &b))
					break ;
			}
		}
		a += 2;
	}
}*/

void improvelog(char **log)
{
    long a;
    long b;

    a = 0;
    while ((*log)[a])
    {
        if ((*log)[a] == 'p' || (*log)[a + 1] == 's' || (*log)[a + 1] == 'r')
            a += 2;
        else
        {
            b = a + 2;
            while ((*log)[b])
            {
                if ((*log)[b] != (*log)[a])
                    break;
                if ((*log)[b + 1] == (*log)[a + 1])
                {
                    // Eliminar operaciones redundantes
                    (*log)[a] = ' ';
                    (*log)[a + 1] = ' ';
                    (*log)[b] = ' ';
                    (*log)[b + 1] = ' ';
                }
                b += 2;
            }
        }
        a += 2;
    }
}

int	countlog(char *log)
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
