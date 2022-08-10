/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:50:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/09 19:07:54 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <defines.h>
# include <stdint.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_rgb
{
	int	green;
	int	red;
	int	blue;
}	t_rgb;




//--------------------------MLX GRAPHIC
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	t_pos	pos;
}	t_data;



typedef struct s_texture
{
	t_data	no;
	t_data	we;
	t_data	ea;
	t_data	so;
}	t_texture;

/* enviroments aux from game */
typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;

	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;

	int		orientation;
	int		side_direction;
}	t_player;


/* variable for size of the map how many bigger rows and columns */
typedef struct s_map_size
{
	int	height;
	int	width;
}	t_map_size;


typedef struct s_aux_ray
{
	int		found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_content;
	float	next_touchx;
	float	next_touchy;
	float	xto_check;
	float	yto_check;
	float	hit_distance;
}			t_aux_ray;

typedef struct s_utils_ray
{
	float		x_intercept;
	float		y_intercept;
	float		x_step;
	float		y_step;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
}			t_utils_ray;

typedef struct s_ray
{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			was_hit_vertical;
	int			wall_hit_cotent;
}				t_ray;


//------------------------------END MLX GRAPHIC


typedef struct s_mode
{
	t_rgb		cell_rgb;
	t_rgb		floor_rgb;


	/* MLX GRAPHIC */

	/* rays */
	t_ray		rays[NUM_RAYS];

	/* t_texture	texture; */
	t_mlx		mlx;
	t_data		img;

	double		dist_proj_plane; //distancia ate a projecao plana/tela |/

	t_player	player;
	t_map_size	map_size;

	/* stucts textures */
	char		***texture_path; //AQUIII
	uint32_t	*textures[NUM_TEXTURES];
	t_texture	sprites;
	/****************************/
	/* end mlx shit */



	/* --------------------------------------------- */
	char		**blueprint; // just the map
	/* all content from map file*/
	char		**map_file; // all the map in the file
	char		***temp_texture;
	char		**temp_color;
	char		***temp_rgb;

	int			map_end_in;
	int			map_start_in;
	int			file_lines;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			rgb_f;
	int			rgb_c;
	int			found_letter;
	int			ht;
}	t_mode;

#endif
