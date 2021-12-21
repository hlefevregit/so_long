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
	t_pos		player_bup;
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