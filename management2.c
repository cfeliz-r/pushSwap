/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:06:52 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/11 17:15:01 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_action_to_log(char **log, char *action)
{
	char	*newlog;
	int		i;

	i = 0;
	newlog = malloc(ft_strlen(*log) + 3);
	if (!newlog)
		return ;
	while ((*log)[i])
	{
		newlog[i] = (*log)[i];
		i++;
	}
	newlog[i++] = action[0];
	newlog[i++] = action[1];
	newlog[i] = 0;
	free(*log);
	*log = newlog;
}

int	try_combine_actions(char **log, char *action, char *last_action)
{
	if ((ft_strcmp(last_action, "ra") == 0 && ft_strcmp(action, "rb") == 0)
		|| (ft_strcmp(last_action, "rb") == 0 && ft_strcmp(action, "ra") == 0))
	{
		(*log)[ft_strlen(*log) - 2] = 'r';
		(*log)[ft_strlen(*log) - 1] = 'r';
		return (1);
	}
	return (0);
}

void	append_log(char **log, char *action)
{
	static char	last_action[3] = "";

	if (!(*log))
	{
		*log = ft_strdup(action);
		ft_strlcpy(last_action, action, 3);
		return ;
	}
	if (try_combine_actions(log, action, last_action))
	{
		ft_strlcpy(last_action, "rr", 3);
		return ;
	}
	append_action_to_log(log, action);
	ft_strlcpy(last_action, action, 3);
}
