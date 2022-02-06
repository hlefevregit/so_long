/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:38:23 by marvin            #+#    #+#             */
/*   Updated: 2021/12/16 16:38:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_is_valid(int argc, char *argv)
{
	if (argc == 1)
		return (errors("y a pas darg gro fdeup"));
	if (argc > 2)
		printf("%s\n", "Seulement le premier argument");
	if (check_ext(argv, ".ber") <= 0)
		return (errors("wrong extension of the file"));
	return (1);
}

void	free_map(char **map_str, t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->line)
		free(map_str[i++]);
	free(map_str[i]);
	i = 0;
	while (i <= map->line)
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
	while (i < line)
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
