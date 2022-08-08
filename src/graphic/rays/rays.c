/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:13:54 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 11:17:04 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	cast_ray(t_mode *mode, float ray_angle, int	col_id);

/**
 * @brief cast all rays and correct that to not have distortion in projection
 * atan esta pegando qual posicao estamos dividido pela distancia que faz a
 * correcao na distorcao pegando o angulo "reto" e nao o distorcido mantendo a
 * mesma distancia para todos os raios
 */
void	cast_all_rays(t_mode *mode)
{
	float	ray_angle;
	int		col_id;

	col_id = 0;
	while (col_id < NUM_RAYS)
	{
		ray_angle = mode->player.rotation_angle + atan((col_id - NUM_RAYS / 2)
				/ mode->dist_proj_plane);
		cast_ray(mode, ray_angle, col_id);
		col_id++;
	}
}

static void	cast_ray(t_mode *mode, float ray_angle, int	col_id)
{

}
