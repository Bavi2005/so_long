/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:38:32 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 00:38:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC 0xff1b
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_W 0x0077
# define KEY_S 0x0073
# define KEY_A 0x0061
# define KEY_D 0x0064
# define TILE_SIZE 64

# include <stdio.h>
# include <stdlib.h>
# include "../library/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"

typedef struct s_sprite
{
	void	*img;
}	t_sprite;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprite	player;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	collectible;
	t_sprite	exit;
	char		**map;
	int			width;
	int			height;
	void		*img;
	t_pos		player_pos;
	int			collectible_count;
	int			move_count;
	int			path_collected_count;
	int			path_exit_found;
}	t_game;

int		return_error(char *message);
void	*return_error_null(char *message);

void	cleanup(t_game *game);
int		check_empty_lines(const char *buf);
int		setup_window(t_game *game);
void	free_map(char **map, int height);
char	**get_map(char *file_name, t_game *game);
int		is_map_valid(char **map, int height, int width, t_game *game);
int		flood_fill(char **map, int height, int width, t_game *game);
int		path_checker(char **map, t_pos player, t_game *game, int height);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
int		check_basic_validations(char **map, int height, int width);
int		check_elements(char **map, int height, int width);

//goyang-goyangg
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);

#endif
