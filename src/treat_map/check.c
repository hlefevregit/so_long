/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:43:08 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:43:08 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	valid_cpe(t_map *map)
{
	if (map->check.collect < 1)
		return (errors("WRONG ! (collectiblr)\n"));
	if (map->check.exit != 1)
		return (errors("WRONG ! (exit)\n"));
	if (map->check.player != 1)
		return (errors("WRONG ! (player)\n"));
	return (1);
}

void	verify(int valid, t_map *map)
{
	if (map->valid == 1)
		map->valid = valid;
}

int	check_wall(char c)
{
	if (c == '1')
		return (1);
	ft_putstr("Error\nNot good map value for walls\n");
	return (0);
}

int	check_char(char c, t_map *map, int col, int line)
{
	if (c == 'P')
	{
		map->check.player += 1;
		map->player.x = col;
		map->player.y = line - 1;
		map->player_ini.x = col;
		map->player_ini.y = line - 1;
	}
	if (c == 'E')
		map->check.exit += 1;
	if (c == 'C')
		map->check.collect += 1;
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

int	check(char c, t_map *map, int col, int line)
{
	int	valid_char;

	valid_char = check_char(c, map, col, line);
	if (valid_char == 0 && c != '\n')
		return (errors("Pas le bon char dans la map"));
	if ((line == 1 || col == 0) && c != '\n')
		return (check_wall(c));
	if ((map->end_col == col) && c != '\n')
		return (check_wall(c));
	return (1);
}
