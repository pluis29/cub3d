/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:45:45 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/16 20:39:07 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	update_variable(t_mode *mode);
static void	start_draw(t_mode *mode);

int	update_loop(t_mode *mode)
{
	update_variable(mode);
	start_draw(mode);
	return (1);
}

static void	update_variable(t_mode *mode)
{
	player_movement(mode);
	cast_all_rays(mode);
}

static void	start_draw(t_mode *mode)
{
	render_game(mode);
	mlx_put_image_to_window(mode->mlx.mlx, mode->mlx.win, mode->img.img, 0, 0);
	mlx_destroy_image(mode->mlx.mlx, mode->img.img);
	mode->img.img = mlx_new_image(mode->mlx.mlx, WIDTH, HEIGHT);
	mode->img.addr = mlx_get_data_addr(mode->img.img, &mode->img.bpp,
			&mode->img.l_len, &mode->img.endian);
}
