/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:49:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/16 21:15:58 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "struct.h"
# include "./libft/libft.h"
# include "ansi_color.h"
# include "defines.h"
# include "./minilibx-linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

int			main(int ac, char **av);

/* start_var */
	/* texture */
void		start_textures(t_mode *mode);
	/* player */
void		start_player_variables(t_mode *mode);
	/* start_enviroments */
void		start_enviroments(t_mode *mode);

/* rays */
	/* rays */
void		cast_all_rays(t_mode *mode);
	/* rays_utils */
void		get_values_of_ray(t_ray *ray, t_utils_ray utils, t_aux_ray horz, t_aux_ray vert);
void		get_ray_distance(t_mode *mode, t_aux_ray *horz, t_aux_ray *vert);
float		normalize_angle(float angle);
	/* rays_facing */
void		ray_facing(t_utils_ray *utils, float ray_angle);
int			is_ray_facing_down(float angle);
int			is_ray_facing_left(float angle);
	/* rays_intersection */
t_aux_ray	horizontal_ray(t_mode *mode, t_utils_ray *utils, float ray_angle);
t_aux_ray	vertical_ray(t_mode *mode, t_utils_ray *utils, float ray_angle);

/* render */
	/* render */
void		render_game(t_mode *mode);
	/* render_utils */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		change_color_intesity(uint32_t *color, float factor);
void		draw_celling(t_mode *mode, t_projection pr);
void		draw_floor(t_mode *mode, t_projection pr);

/* update_var */
	/* handle_events */
int			key_pressed(int keycode, t_mode *mode);
int			key_release(int key, t_mode *mode);
	/* player movement */
void		player_movement(t_mode *mode);
	/* update_loop */
int			update_loop(t_mode *mode);

/* utils */
		/* utils_map.c */
int			is_inside_map(t_mode *mode, float x, float y);
int			has_wall_at(t_mode *mode, float x, float y);


/* rgb */
void		valid_comma(t_mode *mode, char *str, int comma, int i);
int			rgb_aux_separate_ptr(char *str);
void		find_rgb(t_mode *mode, int i);
void		rgb_exists(t_mode *m);

/* texture */
void		find_texture(t_mode *mode, int i);

/* map file*/
void		check_square_space(t_mode *mode, int posi, int x);
void		map_file_redirect(t_mode *mode, char *path);

/* blueprint */
void		check_square_zero(t_mode *mode, int posi, int x);
void		check_blueprint(t_mode *mode);
void		set_blueprint(t_mode *mode);

/* aux */
int			skip_space_cmp(const void *s1, const void *s2, size_t n);
void		look_for_duplicate(t_mode *mode, char *target, int i);
void		check_end_of_file(t_mode *mode);
void		look_for_trash(t_mode *mode);

/* aux free */
void		close_all(t_mode *mode, char *reason);
int			close_aplication(t_mode *mode);
void		free_struct(t_mode *mode);
void		just_close(t_mode *mode);
void		free_mlx(t_mode *mode);


#endif
