# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 00:25:21 by marvin            #+#    #+#              #
#    Updated: 2025/11/06 00:25:21 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = so_long

#SRC        = ... 

CC         = clang
RM         = rm -rf
CFLAGS     = -Wall -Wextra -Werror -g
OBJS       = $(SRC:.c=.o)

#MLX_DIR    = mlx
#MLX        = $(MLX_DIR)/libmlx.a
#MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_DIR  = ./library/libft
LIBFT  = $(LIBFT_DIR)/libft.a
#INCLUDES = -I/usr/include -I$(MLX_DIR) -I$(LIBFT_DIR)/includes


all: $(NAME)

$(LIBFT):
	$(MAKE) --quiet -C $(LIBFT_DIR)

#$(MLX):
#	$(MAKE) --quiet -C $(MLX_DIR)

#$(NAME): $(LIBFT) $(MLX) $(OBJS)
#	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT)

#.c.o:
#	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)*/

clean:
	rm -f $(OBJS)
	$(MAKE) --quiet -C $(LIBFT_DIR) clean
	$(MAKE) --quiet -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) --quiet -C $(LIBFT_DIR) fclean
	# $(MAKE) --quiet -C $(MLX_DIR) fclean


re: fclean all

.PHONY: all bonus clean fclean re rebonus libft ft_printf