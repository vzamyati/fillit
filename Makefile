CC = gcc
C_FLAGS = -Wall -Werror -Wextra
NAME = fillit

SRC_FILES = 

OBJ = $(SRC: .c=.o)
L_FLAGS = -L./libft -lft
LIBFT = libft

all: $(NAME)

.c.o: $(SRC_FILES)
	$(CC) -c $(OBJ) -I./libft $(L_FLAGS) $(C_FLAGS) -o $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -I./libft $(L_FLAGS) $(C_FLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft all

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all