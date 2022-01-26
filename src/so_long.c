/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:36:54 by marvin            #+#    #+#             */
/*   Updated: 2021/12/16 14:36:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_gamestruct(t_game game)
{
	game.side = 0;
	game.init_game = 0;
	game.end_game = 0;
	game.steps = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	start_gamestruct(game);
	if (init_game(game, argc, argv) < 0)
		return (0);
	mlx_hook(game.win, 17, 0, close_win, (void *)&game);
	mlx_hook(game.win, 2, 1L << 0, action, (void *)&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
