/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:25:09 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/09 15:25:09 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		return_error("Invalid number of arguments");
		return (1);
	}
	game.map = get_map(av[1], &game);
	if (!game.map)
		return (1);
	setup_window(&game);
	return (0);
}
