/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:43:35 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:43:35 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_lines(int fd, int cnt_lines, int cnt_col, t_map *map)
{
	int		size;
	char	buffer;

	size = read(fd, &buffer, 1);
	while (size)
	{
		if ((map->end_col == 0) && (buffer == '\n'))
			map->end_col = cnt_col - 1;
		if (size < 0)
			return (errors("On y est presque la mais c cho\n"));
		verify(check(buffer, map, cnt_col, cnt_lines), map);
		if (buffer == '\n')
			cnt_lines++;
		else if (buffer != '\n' && size > 0)
			cnt_col++;
		if (map->end_col != cnt_col - 1 && (buffer == '\n' || size == 0))
			return (errors("(moins de col que de lignes)\n"));
		else if (buffer == '\n')
			cnt_col = 0;
		size = read(fd, &buffer, 1);
	}
	map->col = map->end_col + 1;
	return (cnt_lines);
}

int	lines(char *path, t_map *map)
{
	int	fd;
	int	cnt_lines;
	int	cnt_col;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	cnt_lines = 1;
	cnt_col = 0;
	cnt_lines = count_lines(fd, cnt_lines, cnt_col, map);
	if (cnt_lines <= 0)
		exit(EXIT_FAILURE);
	close(fd);
	return (cnt_lines);
}

static char	**map_alloc(char *path, t_map *map)
{
	char	**map_str;
	int		fd;
	int		i;

	map->line = lines(path, map);
	if (map->valid <= 0)
		exit(EXIT_FAILURE);
	if (map->line <= 0)
		exit(EXIT_FAILURE);
	map_str = malloc(sizeof(char *) * (map->line - 1));
	if (!map_str)
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	i = -1;
	while (map->line - 1 > ++i)
		map_str[i] = get_next_line(fd);
	check_last_lines(map_str[i - 1], map);
	close(fd);
	return (map_str);
}

void	check_last_lines(char *map_str, t_map *map)
{
	int	i;
	int	cpe;

	i = 0;
	while (i <= map->end_col)
	{
		if (map_str[i] == '1')
			i++;
		else
		{
			map->valid = 0;
			break ;
		}
	}
	cpe = valid_cpe(map);
	if (cpe == 0)
		map->valid = 0;
}

char	**read_map(char *path, t_map *map, t_game *game)
{
	char	**map_str;
	int		fd;

	map_str = map_alloc(path, map);
	if (!map_str)
		exit(EXIT_FAILURE);
	backup_map(map, map_str);
	if (map->valid == 0)
	{
		free_map(map_str, map);
		exit(EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	game->map.valid = valid_path(game, fd);
	close(fd);
	if (map->valid == 0)
	{
		free_map(map_str, map);
		exit(EXIT_FAILURE);
	}
	return (map_str);
}
