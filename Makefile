# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 14:43:21 by cfeliz-r          #+#    #+#              #
#    Updated: 2024/06/19 14:20:19 by cfeliz-r         ###   ########.fr        #
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
			management.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
LIBFT = libft.a
LIBFT_PATH = ./libft/
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

all:		${NAME}
${NAME}:	${OBJS} ${LIBFT_PATH}${LIBFT}
			@${CC} ${CFLAGS} ${OBJS} ${LIBFT_PATH}${LIBFT} -o ${NAME}

${LIBFT_PATH}${LIBFT}:	
			@make -C ${LIBFT_PATH} --silent

clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_PATH}
	@echo "Cleaned object files."

fclean:		clean
	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT}
	@echo "Cleaned executable and library."

re:		fclean all

.PHONY: all clean fclean re
