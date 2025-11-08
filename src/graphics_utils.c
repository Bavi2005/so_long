/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:59:15 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/08 23:59:15 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_player_up(game);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player_down(game);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_player_left(game);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_player_right(game);
	return (0);
}

void	cleanup(t_game *game)
{
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->empty.img)
		mlx_destroy_image(game->mlx, game->empty.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map, game->height);
}

void *return_error_null(char *message)
{
	write(1, "Error\n", 6);
	if (message && *message)
	{
		write(1, message, ft_strlen(message));
		write(1, "\n", 1);
	}
	return (NULL);
}