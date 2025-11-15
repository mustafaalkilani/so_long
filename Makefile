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
LIBFT_SRC = $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_bzero.c \
			   $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_isalnum.c \
			   $(LIBFT_DIR)/ft_isalpha.c $(LIBFT_DIR)/ft_isascii.c \
			   $(LIBFT_DIR)/ft_isdigit.c $(LIBFT_DIR)/ft_isprint.c \
			   $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_memchr.c \
			   $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_memcpy.c \
			   $(LIBFT_DIR)/ft_memmove.c $(LIBFT_DIR)/ft_memset.c \
			   $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putendl_fd.c \
			   $(LIBFT_DIR)/ft_putnbr_fd.c $(LIBFT_DIR)/ft_putstr_fd.c \
			   $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strchr.c \
			   $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strjoin.c \
			   $(LIBFT_DIR)/ft_strlcat.c $(LIBFT_DIR)/ft_strlcpy.c \
			   $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strmapi.c \
			   $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_strnstr.c \
			   $(LIBFT_DIR)/ft_strrchr.c $(LIBFT_DIR)/ft_strtrim.c \
			   $(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/ft_tolower.c \
			   $(LIBFT_DIR)/ft_toupper.c
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
PRINTF_SRC = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_putchar.c \
             $(PRINTF_DIR)/ft_puthex_small.c $(PRINTF_DIR)/ft_puthex_caps.c \
             $(PRINTF_DIR)/ft_putnbr.c $(PRINTF_DIR)/ft_putptr.c \
             $(PRINTF_DIR)/ft_putstr.c $(PRINTF_DIR)/ft_put_unsigned_nbr.c \
             $(PRINTF_DIR)/get_size.c
SRC = main.c src/map_load.c src/map_free.c src/map_validate.c \
      src/map_path.c src/game_init.c src/game_render.c src/game_events.c \
      src/game_free.c $(GNL_SRC) $(PRINTF_SRC) $(LIBFT_SRC)

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
	rm -f $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY: all clean fclean re