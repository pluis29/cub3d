/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:01:59 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/16 21:51:59 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	projection_values(t_mode *mode, t_projection *pr);
static void	texture_offset_x(t_mode *mode, t_projection *pr);
static void	inverse_offset_x(t_ray ray, int *t_offset_x);

void	render_game(t_mode *mode)
{
	t_projection pr;

	ft_bzero(&pr, sizeof(t_projection));
	while (pr.x < NUM_RAYS)
	{
		projection_values(mode, &pr);
		draw_celling(mode, pr);
		texture_offset_x(mode, &pr);
		pr.y = pr.wall_top_pixel;
		while (pr.y < pr.wall_bottom_pixel)
		{
			pr.distance_from_top = pr.y + (pr.wall_strip_height / 2)
				- (HEIGHT / 2);
			pr.texture_off_sety = pr.distance_from_top
				* ((float)TEXTURE_HEIGHT / pr.wall_strip_height);
			pr.texel_color = mode->textures[pr.tex_num][(TEXTURE_WIDTH
					* pr.texture_off_sety) + pr.texture_offset_x];
			if (mode->rays[pr.x].was_hit_vertical == true)
				change_color_intesity(&pr.texel_color, 0.7);
			my_mlx_pixel_put(&mode->img, pr.x, pr.y, pr.texel_color);
			pr.y++;
		}
		draw_floor(mode, pr);
		pr.x++;
	}
}

static void	projection_values(t_mode *mode, t_projection *pr)
{
	pr->perp_dist = mode->rays[pr->x].distance
		* cos(mode->rays[pr->x].ray_angle - mode->player.rotation_angle);//get perpendicular distance
	pr->proj_wall_height = (TILE / pr->perp_dist) * mode->dist_proj_plane;
	pr->wall_strip_height = (int)pr->proj_wall_height;

	//aonde a wall comeca (top)
	pr->wall_top_pixel = (HEIGHT / 2) - (pr->wall_strip_height / 2);
	//se de alguma maneira for menor deixa 0 para comecar no topo
	if (pr->wall_top_pixel < 0)
		pr->wall_top_pixel = 0;
	if (pr->wall_top_pixel >= HEIGHT)
		pr->wall_top_pixel = HEIGHT;

	//metade da tela desce mais
	pr->wall_bottom_pixel = (HEIGHT / 2) + (pr->wall_strip_height / 2);
	if (pr->wall_bottom_pixel >= HEIGHT)
		pr->wall_bottom_pixel = HEIGHT;
	if (pr->wall_bottom_pixel < 0)
		pr->wall_bottom_pixel = 0;
}

static void	texture_offset_x(t_mode *mode, t_projection *pr)
{
	if (mode->rays[pr->x].was_hit_vertical == true)
		pr->texture_offset_x = (int)mode->rays[pr->x].wall_hit_y % TILE;
	else
		pr->texture_offset_x = (int)mode->rays[pr->x].wall_hit_x % TILE;
	inverse_offset_x(mode->rays[pr->x], &pr->texture_offset_x);
	pr->tex_num = mode->rays[pr->x].wall_hit_cotent;
}

static void	inverse_offset_x(t_ray ray, int *t_offset_x)
{
	if (ray.was_hit_vertical == false
		&& is_ray_facing_down(ray.ray_angle) == true)
		*t_offset_x = TILE - *t_offset_x;
	if (ray.was_hit_vertical == true
		&& is_ray_facing_left(ray.ray_angle) == true)
		*t_offset_x = TILE - *t_offset_x;
}
