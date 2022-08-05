/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:50:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/05 10:11:14 by jgomes-c         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	t_pos	pos;
}			t_data;

typedef struct s_texture
{
	t_data	no;
	t_data	we;
	t_data	ea;
	t_data	so;
}	t_texture;

typedef struct s_rgb
{
	int	green;
	int	red;
	int	blue;
}	t_rgb;


//MLX GRAPHIC
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
	/* int		side_direction; */
}	t_player;


/* variable for size of the map how many bigger rows and columns */
typedef struct s_map_size
{
	int	height;
	int	width;
}	t_map_size;
//END MLX GRAPHIC


typedef struct s_mode
{
	t_rgb		cell_rgb;
	t_rgb		floor_rgb;
	t_texture	texture;


	/* MLX GRAPHIC */
	t_mlx		s_mlx;
	t_mlx		mlx;
	t_data		img;

	t_player	player;
	t_map_size	map_size;



	/* end mlx shit */


	/* stucts textures */
	char		***texture_path;
	uint32_t	*textures[NUM_TEXTURES];
	t_texture	sprites;
	/****************************/	

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
