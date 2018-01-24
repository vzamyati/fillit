# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 19:19:22 by eaptekar          #+#    #+#              #
#    Updated: 2018/01/22 19:21:15 by eaptekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = valid.c ft_error.c ft_read_file.c ft_strnew.c ft_bzero.c ft_strsub.c print_list.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -c $(FLAGS) $(SRC)
	$(CC) -o $(NAME) main.c $(OBJ)

clean:
	@rm -rf $(OBJ) main.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

