/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:43:21 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:43:21 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_is_valid(int argc, char *argv)
{
	if (argc == 1)
		return (errors("y a pas darg gro fdeup\n"));
	if (argc > 2)
		printf("%s\n", "Seulement le premier argument\n");
	if (check_ext(argv, ".ber") <= 0)
		return (errors("wrong extension of the file\n"));
	return (1);
}

void	free_map(char **map_str, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->line - 1)
		free(map_str[i++]);
	free(map_str[i]);
	i = 0;
	while (i < map->line - 1)
		free(map->save[i++]);
	free(map->save[i]);
}

int	backup_map(t_map *map, char **map_str)
{
	int	i;
	int	line;

	line = map->line;
	map->save = malloc(sizeof(char *) * line + 1);
	if (!map->save)
		return (0);
	i = 0;
	while (i < line - 1)
	{
		map->save[i] = ft_strdup(map_str[i]);
		i++;
	}
	map->save[i] = NULL;
	map->collect = map->check.collect;
	return (1);
}

int	recovery(t_map *map)
{
	int	i;
	int	line;

	i = 0;
	while (i <= map->line)
		free(map->map[i++]);
	free(map->map);
	line = map->line;
	map->map = malloc(sizeof(char *) * line + 1);
	if (!map->map)
		return (0);
	i = 0;
	while (i < line)
	{
		map->map[i] = ft_strdup(map->save[i]);
		i++;
	}
	map->map[i] = NULL;
	map->check.collect = map->collect;
	return (1);
}
