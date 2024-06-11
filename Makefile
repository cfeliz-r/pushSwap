# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 14:43:21 by cfeliz-r          #+#    #+#              #
#    Updated: 2024/06/11 16:53:10 by cfeliz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c \
			c_sort.c \
			c_sort_return.c	\
			line_commands.c	\
			c_slide.c	\
			precaution.c \
			small_nums.c \
			inputs.c \
			join_params.c \
			management.c \
			management2.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
LIBFT = libft.a
LIBFT_PATH = ./libft/
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all:		${NAME}
${NAME}:	${OBJS} ${LIBFT_PATH}${LIBFT}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_PATH}${LIBFT} -o ${NAME}

${LIBFT_PATH}${LIBFT}:	
			make -C ${LIBFT_PATH}

clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_PATH}
	@echo ".o's are no more!"

fclean:		clean
	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT}
	@echo "(including .a's)"

re:		fclean all

.PHONY: all clean fclean re
