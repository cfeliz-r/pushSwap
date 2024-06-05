/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:45:40 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:54:45 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <string.h>

# define MT	99999999999

typedef struct s_towers
{
	long	*a;
	long	*b;
	long	*corr;
	long	size;
	char	*log;
	long	div;
}					t_towers;

int			main(int argc, char **argv);
char		*joinparams(int agc, char **agv);
t_towers	organizestruct(int agc, char **agv);
void		docorrectorder(long *a, long **corr, long size);
int			checkorder(long *a, long size);
void		sx(long **list, long size);
void		px(long **dep, long **arr, long size);
void		rx(long **list, long size);
void		rrx(long **list, long size);
t_towers	chunksort(t_towers tower);
t_towers	returntoa(t_towers	tower, long *min, long *max);
void		addlog(char **log, char *a);
void		printlog(char *log);
void		improvelog(char **log);
int			countlog(char *log);
char		*twonums(long *list);
char		*threenums(long *list);
t_towers	bubblesort(t_towers tower);
t_towers	fivenums(t_towers tower);
void		slideup(long **list, long size);
void		slidedwn(long **list, long size);
void		errmsg(void);

#endif
