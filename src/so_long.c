/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:44:37 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:44:37 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_gamestruct(t_game *game)
{
	game->side = 0;
	game->init_game = 0;
	game->end_game = 0;
	game->steps = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	start_gamestruct(&game);
	if (init_game(&game, argc, argv) < 0)
		return (0);
	mlx_hook(game.win, 2, (1L << 0), action, (void *)&game);
	mlx_hook(game.win, 17, (1L << 0), close_window, (void *)&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
