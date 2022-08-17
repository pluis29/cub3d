/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_facing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:15:19 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/16 21:16:00 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_ray_facing_right(float angle);
static int	is_ray_racing_up(float angle);

void	ray_facing(t_utils_ray *utils, float ray_angle)
{
	utils->is_ray_facing_down = is_ray_facing_down(ray_angle);
	utils->is_ray_facing_up = is_ray_racing_up(ray_angle);
	utils->is_ray_facing_right = is_ray_facing_right(ray_angle);
	utils->is_ray_facing_left = is_ray_facing_left(ray_angle);
}

int	is_ray_facing_down(float angle)
{
	if (angle > 0 && angle < PI)
		return (true);
	else
		return (false);
}

static int	is_ray_racing_up(float angle)
{
	if (is_ray_facing_down(angle) == true)
		return (false);
	else
		return (true);
}

static int	is_ray_facing_right(float angle)
{
	if (angle < 0.5 * PI || angle > 1.5 * PI) //90degress || 270degress
		return (true);
	else
		return (false);
}

int	is_ray_facing_left(float angle)
{
	if (is_ray_facing_right(angle) == true)
		return (false);
	else
		return (true);
}
