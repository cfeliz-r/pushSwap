/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:45:40 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/06 20:36:50 by cfeliz-r         ###   ########.fr       */
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
