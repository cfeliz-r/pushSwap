/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:45:40 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/11 17:04:07 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_towers
{
	int		*stk_a;
	int		*stk_b;
	int		*corr;
	int		size;
	char	*log;
	int		div;
}	t_towers;

int			main(int argc, char **argv);
char		*join_params(int argc, char **argv);
t_towers	initialize_struct(int argc, char **argv);
void		correct_order(int *array, int **correct, int size);
int			is_ordered(int *array, int size);
void		swap_top_two(int **stack, int size);
void		push_to_other_stack(int **src, int **dest, int size);
void		rotate_up(int **stack, int size);
void		rotate_down(int **stack, int size);
t_towers	c_sort(t_towers towers);
t_towers	move_back_to_a(t_towers towers, int *min, int *max);
void		append_log(char **log, char *action);
void		display_log(char *log);
void		optimize_log(char **log);
int			get_log_count(char *log);
char		*sort_two_numbers(int *list);
char		*sort_three_numbers(int *list);
t_towers	bubble_sort(t_towers towers);
t_towers	sort_five_numbers(t_towers towers);
void		shift_up(int **list, int size);
void		shift_down(int **list, int size);
void		print_error(char *str, t_towers *tower);
int			count_rotations(int *list, int target);
void		free_stuff(t_towers *tower);
int			try_combine_actions(char **log, char *action, char *last_action);
void		append_action_to_log(char **log, char *action);

#endif
