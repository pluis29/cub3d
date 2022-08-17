/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:26:06 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/17 11:31:59 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	vert_intersection(t_mode *mode, t_aux_ray *aux,
				t_utils_ray *utils);
static void	horz_intersection(t_mode *mode, t_aux_ray *aux,
				t_utils_ray *utils);

/**
 * @brief get the contact with the wall and delta/step
 */
t_aux_ray	vertical_ray(t_mode *mode, t_utils_ray *utils, float ray_angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = false;
	utils->x_intercept = floor(mode->player.x / TILE) * TILE;
	if (utils->is_ray_facing_right == true)
		utils->x_intercept += TILE;
	utils->y_intercept = mode->player.y + (utils->x_intercept - mode->player.x)
		* tan(ray_angle);
	utils->x_step = TILE;
	if (utils->is_ray_facing_left == true)
		utils->x_step *= -1;
	utils->y_step = TILE * tan(ray_angle);
	if (utils->is_ray_facing_up == true && utils->y_step > 0)
		utils->y_step *= -1;
	if (utils->is_ray_facing_down == true && utils->y_step < 0)
		utils->y_step *= -1;
	vert_intersection(mode, &aux, utils);
	return (aux);
}

static void	vert_intersection(t_mode *mode, t_aux_ray *aux, t_utils_ray *utils)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (is_inside_map(mode, aux->next_touchx, aux->next_touchy) == true)
	{
		aux->yto_check = aux->next_touchy;
		if (utils->is_ray_facing_left == true)
			aux->xto_check = aux->next_touchx + -1;
		else
			aux->xto_check = aux->next_touchx;
		if (has_wall_at(mode, aux->xto_check, aux->yto_check))
		{
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = mode->blueprint[(int)floor(aux->yto_check
					/ TILE)][(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = true;
			break ;
		}
		else
		{
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}

t_aux_ray	horizontal_ray(t_mode *mode, t_utils_ray *utils, float ray_angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = false;
	utils->y_intercept = floor(mode->player.y / TILE) * TILE;
	if (utils->is_ray_facing_down == true)
		utils->y_intercept += TILE;
	utils->x_intercept = mode->player.x + (utils->y_intercept - mode->player.y)
		/ tan(ray_angle);
	utils->y_step = TILE;
	if (utils->is_ray_facing_up == true)
		utils->y_step *= -1;
	utils->x_step = TILE / tan(ray_angle);
	if (utils->is_ray_facing_left == true && utils->x_step > 0)
		utils->x_step *= -1;
	if (utils->is_ray_facing_right == true && utils->x_step < 0)
		utils->x_step *= -1;
	horz_intersection(mode, &aux, utils);
	return (aux);
}

static void	horz_intersection(t_mode *mode, t_aux_ray *aux, t_utils_ray *utils)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (is_inside_map(mode, aux->next_touchx, aux->next_touchy) == true)
	{
		aux->xto_check = aux->next_touchx;
		if (utils->is_ray_facing_up == true)
			aux->yto_check = aux->next_touchy + -1;
		else
			aux->yto_check = aux->next_touchy;
		if (has_wall_at(mode, aux->xto_check, aux->yto_check))
		{
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = mode->blueprint[(int)floor(aux->yto_check
					/ TILE)][(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = true;
			break ;
		}
		else
		{
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}
