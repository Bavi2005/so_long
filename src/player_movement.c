/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:01:43 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/09 00:01:43 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int dir_y, int dir_x)
{
	int	x;
	int	y;

	x = game->player_pos.x + dir_x;
	y = game->player_pos.y + dir_y;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collectible_count--;
	}
	if (game->map[y][x] == 'E')
	{
		if (game->collectible_count == 0)
			close_window(game);
		return ;
	}
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.x = x;
	game->player_pos.y = y;
	game->map[y][x] = 'P';
	game->move_count++;
	ft_printf("Move count : %d\n", game->move_count);
}

void	move_player_up(t_game *game)
{
	move_player(game, -1, 0);
}

void	move_player_down(t_game *game)
{
	move_player(game, 1, 0);
}

void	move_player_left(t_game *game)
{
	move_player(game, 0, -1);
}

void	move_player_right(t_game *game)
{
	move_player(game, 0, 1);
}