# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 12:12:25 by absalem           #+#    #+#              #
#    Updated: 2023/11/21 14:47:21 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= fractol
SRC		= main.c utiles.c
FFLAGS	= -framework OpenGL -framework AppKit
SRCS	= $(SRC:%.c=%.o)

all: $(NAME)

minilibx:
	cd minilibx && make

$(NAME): $(SRCS) minilibx
	$(CC) $(CFLAGS) $(SRCS) $(FFLAGS) minilibx/libmlx.a -o $(NAME)

clean:
	rm -fr $(SRCS)

fclean: clean
	rm -fr $(NAME)
	cd minilibx && make clean

re: fclean all

.PHONY: all clean fclean re minilibx