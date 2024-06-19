/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:45:40 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 14:19:00 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define REF	2147483648

typedef struct s_towers
{
	long		*stk_a;
	long		*stk_b;
	long		*corr;
	long		size;
	char		*log;
	long		div;
}	t_towers;

int			main(int argc, char **argv);
char		*join_params(long argc, char **argv);
t_towers	initialize_struct(long argc, char **argv);
void		correct_order(long *array, long **correct, long size);
long		is_ordered(long *array, long size);
void		swap_top_two(long **stack, long size);
void		push_to_other_stack(long **src, long **dest, long size);
void		rotate_up(long **stack, long size);
void		rotate_down(long **stack, long size);
t_towers	c_sort(t_towers towers);
t_towers	move_back_to_a(t_towers towers, long *min, long *max);
void		append_log(char **log, char *action);
void		display_log(char *log);
char		*sort_two_numbers(long *list);
char		*sort_three_numbers(long *list);
t_towers	bubble_sort(t_towers towers);
t_towers	sort_five_numbers(t_towers towers);
void		shift_up(long **list, long size);
void		shift_down(long **list, long size);
void		print_error(char *str, t_towers *tower);
long		count_rotations(long *list, long target);
void		free_stuff(t_towers *tower);
long		try_combine_actions(char **log, char *action, char *last_action);
void		append_action_to_log(char **log, char *action);
long		div_more_cases(long size);

#endif
