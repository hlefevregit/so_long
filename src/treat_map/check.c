/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2021/12/21 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	valid_cpe(t_map *map)
{
	if (map->check.collect < 1)
		return (errors("WRONG ! (pas de pièces)"));
	if (map->check.exit < 1)
		return (errors("WRONG ! (pas d'exit"));
	if (map->check.player != 1)
		return (errors("WRONG ! Pas de player"));
	return (1);
}

void	verify(int valid, t_map map)
{
	if (map.valid == 1)
		map.valid = valid;
}

int	check_wall(char c)
{
	if (c == 1)
		return (1);
	return (0);
}

int	check_char(char c, t_map map, int col, int line)
{
	if (c == 'P')
	{
		map.check.player += 1;
		map.player.x = col;
		map.player.y = line - 1;
		map.player_ini.x = col;
		map.player_ini.y = line - 1;
	}
	if (c == 'E')
		map.check.exit += 1;
	if (c == 'C')
		map.check.collect += 1;
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

int	check(char c, t_map map, int col, int line)
{
	int	valid_char;

	valid_char = check_char(c, map, col, line);
	if (valid_char == 0 && c != '\n')
		return (errors("Pas le bon char dans la map"));
	if ((line == 1 || col == 0) && c != '\n')
		return (check_wall(c));
	if ((map.end_col == col) && c != '\n')
		return (check_wall(c));
	return (1);
}
