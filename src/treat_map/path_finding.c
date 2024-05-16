/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:04:12 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/16 14:15:50 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map_floodfill(t_map *game)
{
	int	i;

	i = 0;
	while (game->map_floodfill[i])
	{
		free(game->map_floodfill[i]);
		i++;
	}
	free(game->map_floodfill);
}

void	map_malloc_path(t_game *game, int fd)
{
	int		i;
	char	*c;
	int		y;

	i = 0;
	y = game->map.line + 1;
	game->map.map_floodfill = (char **)malloc(sizeof(char *) * y);
	if (!game->map.map_floodfill)
		exit(0);
	while (i < y)
	{
		c = get_next_line(fd);
		game->map.map_floodfill[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}

bool	fill(t_map *game, char c, int line, int col)
{
	static bool		exit = false;
	static int		cols = 0;

	if (line < 0 || col < 0 || line >= game->line - 1 || col >= game->col)
		return (false);
	else if (game->map_floodfill[line][col] == 'X')
		return (false);
	else if (game->map_floodfill[line][col] == '1')
		return (false);
	else if (game->map_floodfill[line][col] == 'E')
		exit = true;
	if (game->map_floodfill[line][col] == 'C')
		cols++;
	game->map_floodfill[line][col] = 'X';
	fill(game, c, line + 1, col);
	fill(game, c, line, col + 1);
	fill(game, c, line - 1, col);
	fill(game, c, line, col - 1);
	return (exit);
}

int	floodfill(t_map *game)
{
	char	b;
	int		line;
	int		col;
	bool	valid;

	b = game->map_floodfill[game->player.y][game->player.x];
	line = game->player.y;
	col = game->player.x;
	valid = fill(game, b, line, col);
	return (valid);
}

int	valid_path(t_game *game, int fd)
{
	map_malloc_path(game, fd);
	if (!floodfill(&game->map))
	{
		ft_putstr("Error\nInvalid path toward the exit\n");
		close(fd);
		return (0);
	}
	free_map_floodfill(&game->map);
	return (1);
}
