/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:31:26 by marvin            #+#    #+#             */
/*   Updated: 2021/12/20 18:31:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_collect(t_pic img, void *mlx)
{
	img.collect.img = mlx_png_file_to_image(mlx, PATH_CO,
		&img.collect.size.x, &img.collect.size.y);
	img.collect.pixel = mlx_get_data_appr(img.collect.img,
		&img.collect.bpp, &img.collect.line_size,
		&img.collect.endian);
}!

void	init_wall(t_pic img, void *mlx)
{
	img.wall.img = mlx_png_file_to_image(mlx, PATH_WA,
		&img.wall.size.x, &img.wall.size.y);
	img.wall.pixel = mlx_get_data_appr(img.wall.img,
		&img.wall.bpp, &img.wall.line_size,
		&img.wall.endian);
}

void	init_exit(t_pic img, void *mlx)
{
	img.exit.img = mlx_png_file_to_image(mlx, PATH_EX,
		&img.exit.size.x, &img.exit.size.y);
	img.exit.pixel = mlx_get_data_appr(img.exit.img,
		&img.exit.bpp, &img.exit.line_size,
		&img.exit.endian);
}

void	init_empty(t_pic img, void *mlx)
{
	img.empty_space.img = mlx_png_file_to_image(mlx, PATH_ES,
		&img.empty_space.size.x, &img.empty_space.size.y);
	img.empty_space.pixel = mlx_get_data_appr(img.empty_space.img,
		&img.empty_space.bpp, &img.empty_space.line_size,
		&img.empty_space.endian);
}

void	init_player(t_pic img, void *mlx)
{
	img.player.south.img = mlx_png_file_to_image(mlx, PATH_PS,
		&img.player.south.size.x, &img.player.south.size.y);
	img.player.south.pixel = mlx_get_data_appr(img.player.south.img,
		&img.player.south.bpp, &img.player.south.line_size,
		&img.player.south.endian);

	img.player.north.img = mlx_png_file_to_image(mlx, PATH_PN,
		&img.player.north.size.x, &img.player.north.size.y);
	img.player.north.pixel = mlx_get_data_appr(img.player.north.img,
		&img.player.north.bpp, &img.player.north.line_size,
		&img.player.north.endian);

	img.player.east.img = mlx_png_file_to_image(mlx, PATH_PE,
		&img.player.east.size.x, &img.player.east.size.y);
	img.player.east.pixel = mlx_get_data_appr(img.player.east.img,
		&img.player.east.bpp, &img.player.east.line_size,
		&img.player.east.endian);
		
	img.player.west.img = mlx_png_file_to_image(mlx, PATH_PW,
		&img.player.west.size.x, &img.player.west.size.y);
	img.player.west.pixel = mlx_get_data_appr(img.player.west.img,
		&img.player.west.bpp, &img.player.west.line_size,
		&img.player.west.endian);
}