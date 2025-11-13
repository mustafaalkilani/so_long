NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
MLX_DIR = minilibx-linux

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source files
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
PRINTF_SRC = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_putchar.c \
             $(PRINTF_DIR)/ft_puthex_small.c $(PRINTF_DIR)/ft_puthex_caps.c \
             $(PRINTF_DIR)/ft_putnbr.c $(PRINTF_DIR)/ft_putptr.c \
             $(PRINTF_DIR)/ft_putstr.c $(PRINTF_DIR)/ft_put_unsigned_nbr.c \
             $(PRINTF_DIR)/get_size.c
SRC = main.c src/map_load.c src/map_free.c src/map_validate.c \
      src/map_path.c src/game_init.c src/game_render.c src/game_events.c \
      src/game_free.c $(GNL_SRC) $(PRINTF_SRC)

# Object files
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re