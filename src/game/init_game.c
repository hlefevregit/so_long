/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:41:43 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:41:43 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_mapstruct(t_map *map)
{
	map->col = 0;
	map->end_col = 0;
	map->line = 0;
	map->valid = 1;
	map->check.collect = 0;
	map->check.player = 0;
	map->check.exit = 0;
	map->collect = 0;
}

char	**init_map(t_game *game, int argc, char **argv)
{
	char	**map;

	if (!map_is_valid(argc, argv[1]))
		exit(EXIT_FAILURE);
	map = read_map(argv[1], &game->map, game);
	if (!map)
		exit(EXIT_FAILURE);
	return (map);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.col * TILES,
			(game->map.line - 1) * TILES, "so_long mon frere");
}

int	init_game(t_game *game, int argc, char **argv)
{
	t_map	map;

	init_mapstruct(&map);
	game->map = map;
	game->map.map = init_map(game, argc, argv);
	if (game->map.map == NULL)
		return (-1);
	init_window(game);
	game->pic = init_image(game->mlx);
	game->side = SOUTH;
	print_map(game);
	game->init_game = 1;
	return (1);
}
