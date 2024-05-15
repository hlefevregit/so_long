/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:43:15 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/07 17:43:15 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_collect(t_pic *img, void *mlx)
{
	img->collect.img = mlx_xpm_file_to_image(mlx, PATH_CO,
			&img->collect.size.x, &img->collect.size.y);
}

void	init_wall(t_pic *img, void *mlx)
{
	img->wall.img = mlx_xpm_file_to_image(mlx, PATH_WA,
			&img->wall.size.x, &img->wall.size.y);
}

void	init_exit(t_pic *img, void *mlx)
{
	img->exit.img = mlx_xpm_file_to_image(mlx, PATH_EX,
			&img->exit.size.x, &img->exit.size.y);
}

void	init_empty(t_pic *img, void *mlx)
{
	img->empty_space.img = mlx_xpm_file_to_image(mlx, PATH_ES,
			&img->empty_space.size.x, &img->empty_space.size.y);
}

void	init_player(t_pic *img, void *mlx)
{
	img->player.south.img = mlx_xpm_file_to_image(mlx, PATH_PS,
			&img->player.south.size.x, &img->player.south.size.y);
	img->player.north.img = mlx_xpm_file_to_image(mlx, PATH_PN,
			&img->player.north.size.x, &img->player.north.size.y);
	img->player.east.img = mlx_xpm_file_to_image(mlx, PATH_PE,
			&img->player.east.size.x, &img->player.east.size.y);
	img->player.west.img = mlx_xpm_file_to_image(mlx, PATH_PW,
			&img->player.west.size.x, &img->player.west.size.y);
}
