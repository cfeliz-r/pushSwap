/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:26:46 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 14:04:34 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prlongf_checker(char s, va_list *args, long *len, long *i)
{
	if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, long), len);
	else if (s == 'u')
		ft_unsigned_long(va_arg(*args, unsigned long), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned long), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned long), len, 'X');
	else if (s == 'p')
		ft_polonger(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putcharacter_length(va_arg(*args, long), len);
	else if (s == '%')
		ft_putcharacter_length('%', len);
	else
		(*i)--;
}

long	ft_prlongf(const char *string, ...)
{
	va_list		args;
	long		i;
	long		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_prlongf_checker(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putcharacter_length((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
