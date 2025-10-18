NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex_small.c ft_printf/ft_puthex_caps.c ft_printf/ft_putnbr.c ft_printf/ft_putptr.c ft_printf/ft_putstr.c ft_printf/ft_put_unsigned_nbr.c ft_printf/get_size.c
SRC = main.c src/map_load.c src/map_free.c src/map_validate.c $(GNL_SRC) $(PRINTF_SRC)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
