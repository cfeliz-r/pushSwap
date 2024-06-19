/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:03:24 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/19 14:01:38 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void			ft_putcharacter_length(char character, long *length);
void			ft_string(char *args, long *length);
void			ft_number(long number, long *length);
void			ft_hexadecimal(unsigned long x, long *length, char x_or_x);
void			ft_unsigned_long(unsigned long u, long *length);
void			ft_polonger(size_t polonger, long *length);
long			ft_prlongf(const char *string, ...);

#endif
