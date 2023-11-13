# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem <absalem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 07:58:40 by absalem           #+#    #+#              #
#    Updated: 2023/08/05 08:13:30 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS    =  ft_printf.c ft_print_unit.c ft_print_hexa.c ft_print_ptr.c \
			ft_print_unsnbr.c \

OBJS = $(SRCS:.c=.o)

CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

