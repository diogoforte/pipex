# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:46:02 by dinunes-          #+#    #+#              #
#    Updated: 2023/04/12 10:46:02 by dinunes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = pipex.h

SRC =  	libft_functions.c \
		libft_functions2.c \
		pipex_utils.c \
		pipex.c \

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRC:.c=.o)
all:$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
clean:
	$(RM)	$(OBJS)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)