/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:53:17 by marvin            #+#    #+#             */
/*   Updated: 2021/12/16 15:53:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_mapstruct(t_map map)
{
	map.col = 0;
	map.line = 0;
	map.valid = 1;
	map.check.collect = 0;
	map.check.player = 0;
	map.check.exit = 0;
}

char	**init_map(t_game game, int argc, char **argv)
{
	char	**map;

	if (!map_is_valid(argc, &argv[1]))
		return (error_null("la carte é pa bone gro nulos"));
	map = read_map(argv[1], game.map);
	if (!map)
		return (error_null("c pa la bone carte mon reuf"));
	return (map);
}

void	init_window(t_game game)
{
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.col * TILES,
			game.map.line * TILES, "so_long mon frere");
}

int	init_game(t_game game, int argc, char **argv)
{
	t_map	map;

	init_mapstruct(map);
	game.map = map;
	game.map.map = init_map(game, argc, argv);
	if (game.map.map == NULL)
		return (-1);
	init_window(game);
	print_map(&game);
	game.init_game = 1;
	return (1);
}
