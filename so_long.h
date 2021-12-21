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
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

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

typedef struct s_side
{
	int	north;
	int	east;
	int	west;
	int	south;
}		t_side;


typedef struct s_valeur
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
}			t_val;


typedef struct	s_pic
{
	t_val	wall;
	t_side	player;
	t_val	exit;
	t_val	collect;
	t_val	empty_space;
}			t_pic;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	int		init_game;
	int		end_game;
	int		steps;
	int		side;
	t_map	map;
	t_pic	pic;
}			t_game;

void	start_gamestruct(t_game game); //1
void	init_mapstruct(t_map map);//3
void	init_window(t_game game); //9
void	print_map(t_game *game); //10
void	verify(int valid, t_map map);
void	move_player(t_game *game, int line, int col, int key);
void	free_map(char **map_str, t_map map);
void	reset(t_game game);
void	kill_player(t_game *game)

int	init_game(t_game game, int argc, char **argv);//2
int	map_is_valid(int argc, char **argv);//5
int	check_ext(char *argv, char *ext); //6
int	errors(char *message);//7
int	valid_cpe(t_map *map); //11
int	check(char c, t_map map, int col, int line);
int	backup_map(t_map *map, char **map_str);
int	action(t_game *game, int key);
int	update(t_game *game);

char	**init_map(t_game game, int argc, char **argv);//4
char	**read_map(char *path, t_map map); //8

void	init_collect(t_pic img, void *mlx);
void	init_wall(t_pic img, void *mlx);
void	init_exit(t_pic img, void *mlx);
void	init_empty(t_pic img, void *mlx);
void	init_player(t_pic img, void *mlx)

#endif