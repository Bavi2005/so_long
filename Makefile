# so_long Makefile (Linux version)

NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Paths
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
MLX_DIR     = ./mlx_linux

# Source files
SRCS := $(wildcard *.c src/*.c)
OBJS := $(SRCS:.c=.o)

# Libraries
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Include directories
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR) -Iinc

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
