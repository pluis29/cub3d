/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_enviroments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 07:56:28 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/05 10:11:33 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_images(t_mode *mode)
{
	mlx_destroy_image(mode->s_mlx.mlx, mode->sprites.no.img);
	mlx_destroy_image(mode->s_mlx.mlx, mode->sprites.so.img);
	mlx_destroy_image(mode->s_mlx.mlx, mode->sprites.we.img);
	mlx_destroy_image(mode->s_mlx.mlx, mode->sprites.ea.img);
}

void	start_enviroments(t_mode *mode)
{
	double	fov;

	//fov = 60 * (PI / 180);
	/* mode->dist_proj_plane = ((WIDTH / 2) / tan(fov / 2)); //importar math.h */
	start_player_variables(mode);
	start_textures(mode);
	free_images(mode);
}
