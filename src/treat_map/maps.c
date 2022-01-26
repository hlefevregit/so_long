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

int	map_is_valid(int argc, char **argv)
{
	if (argc == 1)
		return (error("no arg"));
	if (argc > 2)
		printf("%s\n", "Seulement le premier argument");
	if (check_ext(*argv, ".ber") <= 0)
		return (error("wrong extension of the file"));
	return (1);
}

void	free_map(char **map_str, t_map map)
{
	int	i;

	i = 0;
	while (i <= map.line)
		free(map_str[i++]);
	free(map_str);
	i = 0;
	while (i <= map.line)
		free(map.save[i++]);
	free(map.save);
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
