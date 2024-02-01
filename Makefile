# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 12:12:25 by absalem           #+#    #+#              #
#    Updated: 2023/12/13 14:01:42 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c utiles.c Initialize.c draw.c math.c hook.c

OBJ = $(SRC:.c=.o)
CC = cc

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ) minilibx
	$(CC) $(OBJ) -Lmlx -lm -lmlx -framework OpenGL -framework Appkit -o $(NAME)

minilibx:
	cd mlx && make CFLAGS="-w"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd mlx && make clean

re: fclean all minilibx