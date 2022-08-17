/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_enviroments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 07:56:28 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/17 11:35:47 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_images(t_mode *mode);
static int	mlx_color(t_rgb color);

void	start_enviroments(t_mode *mode)
{
	double	fov;

	fov = 60 * (PI / 180);
	mode->dist_proj_plane = ((WIDTH / 2) / tan(fov / 2));
	start_player_variables(mode);
	start_textures(mode);
	free_images(mode);
	mode->cell = mlx_color(mode->cell_rgb);
	mode->floor = mlx_color(mode->floor_rgb);
}

static int	mlx_color(t_rgb color)
{
	return (color.red << 16 | color.green << 8 | color.blue);
}

static void	free_images(t_mode *mode)
{
	mlx_destroy_image(mode->mlx.mlx, mode->sprites.no.img);
	mlx_destroy_image(mode->mlx.mlx, mode->sprites.so.img);
	mlx_destroy_image(mode->mlx.mlx, mode->sprites.we.img);
	mlx_destroy_image(mode->mlx.mlx, mode->sprites.ea.img);
}
