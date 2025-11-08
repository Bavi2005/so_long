/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:00:54 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/09 00:00:54 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	can_reach_element(char **map, t_pos player, t_game *game)
{
	if (player.x < 0 || player.y < 0
		|| map[player.y] == NULL
		|| map[player.y][player.x] == '\0')
		return ;
	if (map[player.y][player.x] == '1' || map[player.y][player.x] == 'X' || map[player.y][player.x] == 'E')
	{
		if (map[player.y][player.x] == 'E')
			game->path_exit_found = 1;
		return ;
	}
	if (map[player.y][player.x] == 'C')
		game->path_collected_count++;
	else if (map[player.y][player.x] == 'E')
		game->path_exit_found = 1;
	map[player.y][player.x] = 'X';
	can_reach_element(map, (t_pos){player.x, player.y - 1}, game);
	can_reach_element(map, (t_pos){player.x, player.y + 1}, game);
	can_reach_element(map, (t_pos){player.x - 1, player.y}, game);
	can_reach_element(map, (t_pos){player.x + 1, player.y}, game);
}

int	path_checker(char **map, t_pos player, t_game *game, int height)
{
	game->path_collected_count = 0;
	game->path_exit_found = 0;
	can_reach_element(map, player, game);
	free_map(map, height);
	if (game->path_collected_count != game->collectible_count)
		return (return_error("Invalid map: Can't access all collectibles"));
	if (game->path_exit_found != 1)
		return (return_error("Invalid map: No path to exit"));
	return (0);
}
