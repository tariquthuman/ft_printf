# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadmoham <kadmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 20:00:47 by kadmoham          #+#    #+#              #
#    Updated: 2024/06/29 13:12:26 by kadmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

SRC = $(wildcard *.c)
OBJ =	$(SRC:.c=.o)

NAME =	libftprintf.a

NAMELIBFT = libft.a

INCLUDES = ./libft/

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C libft
	cp ./libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	cc -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY:	all clean fclean re
