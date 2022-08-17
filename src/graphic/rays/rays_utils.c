/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:02:59 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/13 13:11:34 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static float	distance_between_points(float x1, float y1, float x2,
		float y2);

/* matem sempre entre 0 e 2 pi */
float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0) //se negativo coloca no lado positivo
		angle = TWO_PI + angle;
	return (angle);
}

//so se achar uma colisao um hit horizontal ou vertical
void	get_ray_distance(t_mode *mode, t_aux_ray *horz, t_aux_ray *vert)
{
	if (horz->found_wall_hit == true)
		horz->hit_distance = distance_between_points(
				mode->player.x, mode->player.y, horz->wall_hit_x,
				horz->wall_hit_y);
	else
		horz->hit_distance = INT_MAX;
	if (vert->found_wall_hit == true)
		vert->hit_distance = distance_between_points(
				mode->player.x, mode->player.y, vert->wall_hit_x,
				vert->wall_hit_y);
	else
		vert->hit_distance = INT_MAX;
}

static float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

//so armazena a menor distancia
void	get_values_of_ray(t_ray *ray, t_utils_ray utils, t_aux_ray horz,
	t_aux_ray vert)
{
	if (vert.hit_distance < horz.hit_distance)
	{
		ray->distance = vert.hit_distance;
		ray->wall_hit_x = vert.wall_hit_x;
		ray->wall_hit_y = vert.wall_hit_y;
		ray->wall_hit_cotent = vert.wall_content;
		if (utils.is_ray_facing_left == true)
			ray->wall_hit_cotent = WE;
		else
			ray->wall_hit_cotent = EA;
		ray->was_hit_vertical = true;
	}
	else
	{
		ray->distance = horz.hit_distance;
		ray->wall_hit_x = horz.wall_hit_x;
		ray->wall_hit_y = horz.wall_hit_y;
		ray->wall_hit_cotent = horz.wall_content;
		if (utils.is_ray_facing_up == true)
			ray->wall_hit_cotent = NO;
		else
			ray->wall_hit_cotent = SO;
		ray->was_hit_vertical = false;
	}
}
