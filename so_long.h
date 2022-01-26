/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:54:27 by marvin            #+#    #+#             */
/*   Updated: 2021/12/16 14:54:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILES 50
# define NORTH 0x77
# define SOUTH 0x73
# define EAST 0x64
# define WEST 0x61
# define ESC 0xff1b
# define R 0x15
# define PATH_EX "./sprite/so_long_exit.png"
# define PATH_CO "./sprite/so_long_collect.png"
# define PATH_WA "./sprite/so_long_wall.png"
# define PATH_ES "./sprite/so_long_empty.png"
# define PATH_PE "./sprite/so_long_player_east.png"
# define PATH_PS "./sprite/so_long_player_east.png"
# define PATH_PW "./sprite/so_long_player_west.png"
# define PATH_PN "./sprite/so_long_player_west.png"

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include "src/gnl/get_next_line.h"
# include <mlx.h>

typedef struct s_position
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_check_map
{
	int	player;
	int	exit;
	int	collect;
}		t_map_check;

typedef struct s_map
{
	t_pos		player;
	int			valid;
	int			col;
	int			line;
	int			end_col;
	int			collect;
	t_pos		player_ini;
	t_map_check	check;
	char		**map;
	char		**save;
}				t_map;

typedef struct s_valeur
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
}			t_val;

typedef struct s_side
{
	t_val	north;
	t_val	east;
	t_val	west;
	t_val	south;
}		t_side;

typedef struct s_pic
{
	t_val	wall;
	t_side	player;
	t_val	exit;
	t_val	collect;
	t_val	empty_space;
}			t_pic;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		init_game;
	int		end_game;
	int		steps;
	int		side;
	float	reset;
	t_map	map;
	t_pic	pic;
}			t_game;

void	start_gamestruct(t_game game);
void	init_mapstruct(t_map map);
void	init_window(t_game game);
void	print_map(t_game *game);
void	verify(int valid, t_map map);
void	move_player(t_game *game, int line, int col, int key);
void	free_map(char **map_str, t_map map);
void	reset(t_game *game);
void	kill_player(t_game *game);
void	check_last_lines(char *map_str, t_map map);

int		init_game(t_game game, int argc, char **argv);
int		map_is_valid(int argc, char **argv);
int		check_ext(char *argv, char *ext);
int		errors(char *message);
int		valid_cpe(t_map *map);
int		check(char c, t_map map, int col, int line);
int		backup_map(t_map *map, char **map_str);
int		action(t_game *game, int key);
int		update(t_game *game);

char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
char	**init_map(t_game game, int argc, char **argv);
char	**read_map(char *path, t_map map);

void	init_collect(t_pic *img, void *mlx);
void	init_wall(t_pic *img, void *mlx);
void	init_exit(t_pic *img, void *mlx);
void	init_empty(t_pic *img, void *mlx);
void	init_player(t_pic *img, void *mlx);

#endif