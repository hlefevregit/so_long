/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:56:18 by marvin            #+#    #+#             */
/*   Updated: 2021/12/20 22:56:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_lines(int fd, int cnt_lines, int cnt_col, t_map map)
{
	int		size;
	char	buffer;

	while (true)
	{
		size = read(fd, &buffer, 1);
		if (size < 0)
			return (errors("On y est presque la mais c cho"));
		verify(check(buffer, map, cnt_col, cnt_lines), map);
		if (buffer == '\n')
			cnt_lines++;
		else if (buffer != '\n' && size > 0)
			cnt_col++;
		if ((map.end_col == 0) && (buffer == '\n'))
			map.end_col = cnt_col - 1;
		if (map.end_col != cnt_col - 1 && (buffer == '\n' || size == 0))
			return (errors("(moins de col que de lignes)"));
		else if (buffer == '\n')
			cnt_col = 0;
		if (size == 0)
			break ;
	}
	map.col = map.end_col + 1;
	return (cnt_lines);
}

int	lines(char *path, t_map map)
{
	int	fd;
	int	cnt_lines;
	int	cnt_col;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (errors("Pas bon ça frérot fait un effort"));
	cnt_lines = 1;
	cnt_col = 0;
	cnt_lines = count_lines(fd, cnt_lines, cnt_col, map);
	if (cnt_lines <= 0)
		return (errors("Non mais ça casse les couilles la"));
	close(fd);
	return (cnt_lines);
}

static char	**map_alloc(char *path, t_map map)
{
	char	**map_str;

	map.line = lines(path, map);
	if (map.valid <= 0)
		return (error_null("map invalide mon gars"));
	if (map.line <= 0)
		return (error_null("map invalide mec"));
	map_str = malloc(sizeof(char *) * map.line + 1);
	if (!map_str)
		return (error_null("map invalide frerot (malloc)"));
	return (map_str);
}

void	check_last_lines(char *map_str, t_map map)
{
	int	i;
	int	cpe;

	i = 0;
	while (i < map.end_col)
	{
		if (map_str[i] == '1')
			i++;
		else
		{
			map.valid = 0;
			break ;
		}
	}
	cpe = valid_cpe(&map);
	if (cpe == 0)
		map.valid = 0;
}

char	**read_map(char *path, t_map map)
{
	int		fd;
	int		i;
	char	**map_str;

	map_str = map_alloc(path, map);
	if (!map_str)
		return (error_null("Error d'alloc"));
	fd = open(path, O_RDONLY);
	i = 0;
	while (map_str)
		map_str[i++] = get_next_line(fd);
	check_last_line(map_str[i - 1], map);
	backup_map(&map, map_str);
	if (map.valid == 0)
	{
		free_map(map_str, map);
		return (error_null("map invalide mon pote"));
	}
	close(fd);
	return (map_str);
}
