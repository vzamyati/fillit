
SRC = 	main.c \
		valid.c \
		ft_error.c \
		ft_read_file.c \
		ft_strnew.c \ 

OBJ = $(SRC:.c=.o)

NAME = fillit

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

