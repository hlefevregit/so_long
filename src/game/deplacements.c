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
	if (key == SOUTH)
		game.side = SOUTH;
	else if (key == NORTH)
		game.side = NORTH;
	else if (key == EAST)
		game.side = EAST;
	else if (key == WEST)
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

int	verify_move(t_game *game, int line, int col, int key)
{
	if (game.map.map[line][col] == '1')
		return (-1);
	if (game.map.map[line][col] == 'E' && game->map.check.collect == 0)
		game->end_game = 1;
	if (game->map.map[line][col] == 'E')
		return (-1);
	if (game->end_game)
		return (-1);
	if (key != NORTH && key != EAST && key != WEST && key != SOUTH)
		return (-1);
	else
		return (1);
}