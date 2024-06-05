/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cksort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:13 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 21:37:03 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numsinrange(long *list, long sol, long max, long min)
{
	long	a;

	a = 0;
	while (a < sol)
	{
		if (list[a] >= min && list[a] <= max)
			return (1);
		a++;
	}
	return (0);
}

/*static t_towers	movetob(t_towers tower, long min, long max)
{
	while (numsinrange(tower.a, tower.size, max, min))
	{
		if (tower.a[0] >= min && tower.a[0] <= max)
		{
			px(&tower.a, &tower.b, tower.size);
			addlog(&tower.log, "pb");
		}
		else
		{
			rx(&tower.a, tower.size);
			addlog(&tower.log, "ra");
		}
	}
	return (tower);
}*/

static t_towers movetob(t_towers tower, long min, long max)
{
    while (numsinrange(tower.a, tower.size, max, min))
    {
        if (tower.a[0] >= min && tower.a[0] <= max)
        {
            // Mover el primer elemento de A a B
            px(&tower.a, &tower.b, tower.size);
            addlog(&tower.log, "pb");
        }
        else
        {
            // Rotar pila A si el primer elemento no está en el rango
            rx(&tower.a, tower.size);
            addlog(&tower.log, "ra");
        }    
    }
    return (tower);
}

/*t_towers	chunksort(t_towers tower)
{
	long	amogr;
	long	round;
	long	*max;
	long	*min;

	amogr = (tower.size / (long)tower.div) + !!(tower.size % (long)tower.div);
	round = amogr;
	while (round > 0)
	{
		if (round == amogr)
			max = &tower.corr[tower.size - 1];
		else
			max = &tower.corr[(tower.size / amogr) * round];
		min = &tower.corr[(tower.size / amogr) * (--round)];
		tower = movetob(tower, *min, *max);
		tower = returntoa(tower, min, max);
	}
	while (tower.a[round] != tower.corr[0])
	{
		rrx(&(tower.a), tower.size);
		addlog(&tower.log, "Ra");
	}
	return (tower);
}*/

t_towers chunksort(t_towers tower)
{
    long amogr;
    long round;
    long *max;
    long *min;

    // Ajuste del tamaño de chunk para optimización
    amogr = (tower.size / (long)tower.div) + !!(tower.size % (long)tower.div);
    round = amogr;

    while (round > 0)
    {
        if (round == amogr)
            max = &tower.corr[tower.size - 1];
        else
            max = &tower.corr[(tower.size / amogr) * round];
        min = &tower.corr[(tower.size / amogr) * (--round)];

        // Mover elementos dentro del rango actual a la pila B
        tower = movetob(tower, *min, *max);
        // Devolver elementos a la pila A en el orden correcto
        tower = returntoa(tower, min, max);
    }
    
    // Alinear pila A con el elemento más pequeño en la posición correcta
    while (tower.a[0] != tower.corr[0])
    {
        rrx(&(tower.a), tower.size);
        addlog(&tower.log, "rra");
    }
    
    return (tower);
}
