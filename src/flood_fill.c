/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:00:14 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/09 00:00:14 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "../library/libft/libft.h"

static t_pos	find_char(char **map, t_pos start, char element, int height)
{
	t_pos	find;
	int		x;
	int		y;

	find.y = -1;
	find.x = -1;
	y = start.y;
	x = start.x;
	while (y < height && map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0' && x < (int)ft_strlen(map[y]))
		{
			if (map[y][x] == element)
			{
				find.y = y;
				find.x = x;
				return (find);
			}
			x++;
		}
		y++;
	}
	return (find);
}

static char	*make_row_copy(char *current_row, int width)
{
	char	*new_row;

	new_row = (char *)ft_calloc(width + 1, sizeof(char));
	if (new_row == NULL)
		return (NULL);
	ft_strcpy(new_row, current_row);
	return (new_row);
}

static char	**copy_map(char **main_map, int height, int width)
{
	int		y;
	char	**new_map;

	new_map = (char **)ft_calloc(height + 1, sizeof(char *));
	if (new_map == NULL)
		return (NULL);
	y = 0;
	while (y < height)
	{
		new_map[y] = make_row_copy(main_map[y], width);
		if (new_map[y] == NULL)
		{
			free_map(new_map, y);
			return (NULL);
		}
		y++;
	}
	return (new_map);
}

int	flood_fill(char **map, int height, int width, t_game *game)
{
	char	**map_copy;
	t_pos	player;
	t_pos	start_pos;

	map_copy = copy_map(map, height, width);
	if (!map_copy)
		return (return_error("Error: Unable to create map copy"));
	start_pos.x = 0;
	start_pos.y = 0;
	player = find_char(map_copy, start_pos, 'P', height);
	game->player_pos = player;
	return (path_checker(map_copy, player, game, height));
}
