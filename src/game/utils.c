/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:59:20 by marvin            #+#    #+#             */
/*   Updated: 2021/12/21 21:59:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	kill_player(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	game->map.map[x][y] = '0';
	game->side = SOUTH;
	print_map(game);
}

void	reset(t_game *game)
{
	recovery(game->map);
	game->map.player.x = game->map.player_ini.x;
	game->map.player.y = game->map.player_ini.y;
	game->end_game = 0;
	game->steps = 0;
	game->side = SOUTH;
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
	free_map(game->map.map, game->map);
	exit(0);
}

int	action(t_game *game, int key)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (key == ESC)
		close_window(game);
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
