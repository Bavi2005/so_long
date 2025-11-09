/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/11/08 23:59:44 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/08 23:59:44 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_elements(char **map, int height, int width, char element)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_elements(char **map, int height, int width)
{
	int	y;
	int	x;
	int	line_length;

	y = 0;
	while (y < height)
	{
		if (map[y][0] == '\0' || map[y][0] == '\n')
			return (1);
		line_length = 0;
		x = 0;
		while (map[y][x] != '\0')
		{
			if (!(map[y][x] == '0' || map[y][x] == '1' || map[y][x] == 'C'
					|| map[y][x] == 'E' || map[y][x] == 'P'))
				return (1);
			x++;
			line_length++;
		}
		if (line_length != width)
			return (1);
		y++;
	}
	return (0);
}

static int	check_upper_lower_walls(char **map, int width, int height)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (map[0][x] == '1' && map[height - 1][x] == '1')
			x++;
		else
			return (1);
	}
	return (0);
}

static int	check_side_walls(char **map, int height, int width)
{
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] == '1' && map[y][width - 1] == '1')
			y++;
		else
			return (1);
	}
	return (0);
}

int	is_map_valid(char **map, int height, int width, t_game *game)
{
	int	exit_count;
	int	player_count;
	int	collect_count;

	if (check_basic_validations(map, height, width))
		return (1);
	exit_count = count_elements(map, height, width, 'E');
	player_count = count_elements(map, height, width, 'P');
	collect_count = count_elements(map, height, width, 'C');
	if (exit_count != 1 || player_count != 1 || collect_count == 0)
		return (return_error("Invalid map: Missing or too many elements"));
	game->collectible_count = collect_count;
	if (check_upper_lower_walls(map, width, height) == 1
		|| check_side_walls(map, height, width) == 1)
		return (return_error("Invalid map: Missing walls"));
	if (flood_fill(map, height, width, game) == 1)
		return (1);
	return (0);
}
