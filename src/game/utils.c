/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:41:51 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:41:51 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	reset(t_game *game)
{
	recovery(&game->map);
	game->map.player.x = game->map.player_ini.x;
	game->map.player.y = game->map.player_ini.y;
	game->end_game = 0;
	game->steps = 0;
	game->side = SOUTH;
}

void	kill_player(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	game->map.map[y][x] = '0';
	game->side = SOUTH;
	print_map(game);
}

int	update(t_game *game)
{
	if (game->reset)
		game->reset += 0.1;
	else if (game->end_game < 1)
	{
		mlx_clear_window(game->mlx, game->win);
		game->reset = 0;
	}
	print_map(game);
	return (0);
}

int	close_window(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(0);
}

int	action(int key, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	printf("%i\n", key);
	if (key == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		close_window(game);
	}
	if (key == R)
		reset(game);
	if (key == NORTH)
		line--;
	if (key == SOUTH)
		line++;
	if (key == EAST)
		col++;
	if (key == WEST)
		col--;
	if (!game->end_game)
		move_player(game, line, col, key);
	return (1);
}
