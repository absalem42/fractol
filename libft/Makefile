# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem <absalem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 13:22:27 by absalem           #+#    #+#              #
#    Updated: 2023/07/26 08:46:47 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_isalnum.c ft_isprint.c ft_strlcat.c ft_strncmp.c ft_isalpha.c \
       ft_memcpy.c ft_strlcpy.c ft_strchr.c ft_tolower.c ft_bzero.c \
       ft_isascii.c ft_strlen.c ft_memmove.c ft_strrchr.c ft_toupper.c \
       ft_isdigit.c ft_memset.c ft_memchr.c ft_memcmp.c ft_atoi.c \
       ft_strnstr.c ft_calloc.c ft_substr.c ft_strdup.c ft_putstr_fd.c \
       ft_putchar_fd.c ft_putendl_fd.c ft_strjoin.c ft_strtrim.c \
       ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_split.c ft_itoa.c\

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

