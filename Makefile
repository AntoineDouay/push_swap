# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouay <adouay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 23:33:03 by adouay            #+#    #+#              #
#    Updated: 2022/10/14 15:00:57 by adouay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc -Werror -Wextra -Wall

SRC = main.c \
	parsing.c \
	stack.c \
	action.c \
	algo.c \
	radix.c \
	free.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C libft
	$(CC)  $(OBJ) -g -L libft/. -lft -I libft/. -o $(NAME)
	echo "\033[32mPush_swap Done\033[0m"

%.o: %.c
	$(CC) -c $^ 

clean:
	rm -f $(OBJ)
	$(MAKE) fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all