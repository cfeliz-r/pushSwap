# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 09:51:30 by cfeliz-r          #+#    #+#              #
#    Updated: 2024/06/03 16:52:34 by cfeliz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strcmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_printf/ft_printf.c \
		  ft_printf/ft_number.c \
		  ft_printf/ft_words.c \
		  get_next_line/get_next_line.c


OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

%.o: %.c libft.h
		${CC} ${CFLAGS} -I. -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS} libft.h
		ar rcs ${NAME} ${OBJS}

clean:
		rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re