# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 12:12:25 by absalem           #+#    #+#              #
#    Updated: 2023/10/28 12:12:27 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME1	=	server
NAME2	=	client

LIBS	=	libft/libft.a ft_printf/libftprintf.a

SRC2	=	client.c
SRC1	=	server.c

SRCS2	=	$(SRC2:%.c=%.o)
SRCS1	=	$(SRC1:%.c=%.o)

all : $(NAME1) $(NAME2)

$(NAME1) $(NAME2) : $(SRCS1) $(SRCS2)
	@make all -C ./ft_printf 
	@make all -C ./libft
	$(CC) $(CFLAGS) $(SRC1) $(LIBS) -o $(NAME1) 
	$(CC) $(CFLAGS) $(SRC2) $(LIBS) -o $(NAME2) 

clean:
	@make clean -C ./libft
	@make clean -C ./ft_printf
	rm -fr $(SRCS1) $(SRCS2) 

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	rm -fr $(NAME1) $(NAME2) 

re: fclean all