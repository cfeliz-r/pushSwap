/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:45:40 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 16:17:57 by cfeliz-r         ###   ########.fr       */
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
/*
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
void		errmsg(void);*/
int         main(int argc, char **argv);
char*       join_params(int argc, char **argv);
t_towers    initialize_struct(int argc, char **argv);
void        correct_order(long *array, long **correct, long size);
int         is_ordered(long *array, long size);
void        swap_top_two(long **stack, long size);
void        push_to_other_stack(long **src, long **dest, long size);
void        rotate_up(long **stack, long size);
void        rotate_down(long **stack, long size);
t_towers    c_sort(t_towers towers);
t_towers    move_back_to_a(t_towers towers, long *min, long *max);
void        append_log(char **log, char *action);
void        display_log(char *log);
void        optimize_log(char **log);
int         get_log_count(char *log);
char*       sort_two_numbers(long *list);
char*       sort_three_numbers(long *list);
t_towers    bubble_sort(t_towers towers);
t_towers    sort_five_numbers(t_towers towers);
void        shift_up(long **list, long size);
void        shift_down(long **list, long size);
void        print_error(void);

#endif
