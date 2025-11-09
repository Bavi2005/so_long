/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:49:09 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/08 23:49:09 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../library/libft/ft_printf.h"

int	return_error(char *message)
{
	write(1, "Error\n", 6);
	if (message && *message)
	{
		write(1, message, ft_strlen(message));
		write(1, "\n", 1);
	}
	return (1);
}

int	check_empty_lines(const char *buffer)
{
	int	i;
	int	newline_num;

	i = 0;
	newline_num = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			newline_num++;
			if (newline_num > 1)
				return (1);
		}
		else
			newline_num = 0;
		i++;
	}
	return (0);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
