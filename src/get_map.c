/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:52:31 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/08 23:52:31 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../library/libft/get_next_line.h"

int	check_file_name(char *file_path)
{
	char	*base;
	int	len;

	base = ft_strrchr(file_path, '/');
	base = base ? base + 1 : file_path;

	len = ft_strlen(base);
	if (len < 5 || ft_strncmp(base + len - 4, ".ber", 4) != 0)
		return (1);
	if (base[0] == '.')
		return (1);
	return (0);
}

static char	*file_reading(int fd)
{
	char	*line;
	char	*buf;
	char	*temp;

	buf = ft_calloc(1, 1);
	if (buf == NULL)
		exit(0);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(buf, line);
		free(buf);
		free(line);
		if (!temp)
			return (NULL);
		buf = temp;
		line = get_next_line(fd);
	}
	return (buf);
}

static	char	*read_and_validate_file(char *file_path)
{
	int		fd;
	char	*buf;

	if (check_file_name(file_path) == 1)
	{
		return_error("Bad extension");
		return (NULL);
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (return_error_null("Permission denied"));
	buf = file_reading(fd);
	if (buf == NULL || check_empty_lines(buf) == 1)
	{
		return_error("Invalid map: Empty lines");
		return (NULL);
	}
	return (buf);
}

static void	get_dimensions(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		y++;
	}
	game->height = y;
	game->width = x;
}

char	**get_map(char *file_name, t_game *game)
{
	char	**map;
	char	*buf;

	buf = read_and_validate_file(file_name);
	if (!buf)
		return (NULL);
	map = ft_split(buf, '\n');
	free(buf);
	if (!map)
		exit(0);
	get_dimensions(map, game);
	if (is_map_valid(map, game->height, game->width, game) == 1)
	{
		free_map(map, game->height);
		return (NULL);
	}
	return (map);
}