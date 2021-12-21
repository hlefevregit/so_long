/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:46:39 by marvin            #+#    #+#             */
/*   Updated: 2021/12/20 22:46:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_side(t_game *game, int key)
{
	if (key == "DOWN")
		game.side = SOUTH;
	else if (key == "UP")
		game.side = NORTH;
	else if (key == "RIGHT")
		game.side = EAST;
	else if (key == "LEFT")
		game.side = WEST;
}

void	move_player(t_game *game, int line, int col, int key)
{
	int	x;
	int	y;
	int	valid;

	x = game->map.player.x;
	y = game->map.player.y;
	valid = verify_move(game, line, col, key);
	check_side(game, key);
	if (game->end_game)
		kill_player(game);
	if (valid > 0)
	{
		if (game->map.map[line][col] == "C")
			game->map.check.collect--;
		game->map.map[y][x] = '0';
		game->map.map[line][col] = "P";
		game->map.player.y = line;
		game->map.player.x = col;
		game->steps++;
	}
}