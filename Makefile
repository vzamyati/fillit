# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 19:19:22 by eaptekar          #+#    #+#              #
#    Updated: 2018/01/24 15:17:10 by eaptekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror -I.

SRC = valid.c ft_read_file.c map.c libfunctions.c solver.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) main.c $(OBJ)

%.o: %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@rm -rf $(OBJ) main.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
