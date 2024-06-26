/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:43:27 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:43:27 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_pic	init_image(void *mlx)
{
	t_pic	img;

	init_wall(&img, mlx);
	init_exit(&img, mlx);
	init_player(&img, mlx);
	init_collect(&img, mlx);
	init_empty(&img, mlx);
	return (img);
}

void	print_player(t_game *game, t_pos pos)
{
	if (game->side == NORTH)
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.player.north.img, pos.x, pos.y);
	else if (game->side == SOUTH)
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.player.south.img, pos.x, pos.y);
	else if (game->side == EAST)
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.player.east.img, pos.x, pos.y);
	else if (game->side == WEST)
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.player.west.img, pos.x, pos.y);
}

static void	sprite_print_obj(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line][col] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.exit.img, x, y);
	if (game->map.map[line][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.collect.img, x, y);
}

static void	sprite_print_env(t_game *game, int line, int col)
{
	int		x;
	int		y;
	t_pos	pos;

	pos.x = col * TILES;
	pos.y = line * TILES;
	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line][col] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.wall.img, x, y);
	if (game->map.map[line][col] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->pic.empty_space.img, x, y);
	if (game->map.map[line][col] == 'P')
		print_player(game, pos);
}

void	print_map(t_game *game)
{
	int		line;
	int		col;
	char	*str;

	line = -1;
	while (++line < game->map.line - 1)
	{
		col = -1;
		while (++col < game->map.col + 1)
		{
			sprite_print_env(game, line, col);
			sprite_print_obj(game, line, col);
		}
		str = ft_itoa(game->steps);
		mlx_string_put(game->mlx, game->win, 120, 25, 0xFF0000, str);
		free(str);
		if (game->end_game)
			mlx_string_put(game->mlx, game->win, 150, 25, 0xFFFFFF,
				"You won, press R to play again");
	}
	while (++col < game->map.col + 1)
	{
		sprite_print_env(game, line, col);
		sprite_print_obj(game, line, col);
	}
}
