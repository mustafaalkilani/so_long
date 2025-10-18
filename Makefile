NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC = main.c src/map_load.c src/map_free.c $(GNL_SRC) 		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
