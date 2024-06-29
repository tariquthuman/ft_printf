# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 19:57:50 by mthottap          #+#    #+#              #
#    Updated: 2024/06/23 19:57:58 by mthottap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

FLAGS = -Wall -Werror -Wextra

SRC = $(wildcard *.c)
OBJ =	$(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	cc -nostartfiles -fPIC $(FLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re