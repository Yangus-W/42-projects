# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yawang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:59:36 by yawang            #+#    #+#              #
#    Updated: 2024/01/17 19:38:26 by yawang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c print_char.c print_digit.c print_digit_hexa.c print_ptr.c \
	print_str.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re
