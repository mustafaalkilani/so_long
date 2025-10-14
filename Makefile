NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c map_load.c map_free.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
