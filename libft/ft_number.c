/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:25:46 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 14:05:04 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(long number, long *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putcharacter_length('-', length);
		ft_number(number * -1, length);
	}
	else
	{
		if (number > 9)
			ft_number(number / 10, length);
		ft_putcharacter_length(number % 10 + '0', length);
	}
}

void	ft_polonger(size_t polonger, long *length)
{
	char	string[25];
	long	i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length) += 2;
	if (polonger == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (polonger != 0)
	{
		string[i] = base_character[polonger % 16];
		polonger = polonger / 16;
		i++;
	}
	while (i--)
	{
		ft_putcharacter_length(string[i], length);
	}
}

void	ft_hexadecimal(unsigned long x, long *length, char x_or_x)
{
	char	string[25];
	char	*base_character;
	long	i;

	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharacter_length(string[i], length);
}

void	ft_unsigned_long(unsigned long u, long *length)
{
	if (u >= 10)
		ft_unsigned_long(u / 10, length);
	ft_putcharacter_length(u % 10 + '0', length);
}
