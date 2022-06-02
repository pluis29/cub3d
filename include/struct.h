/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:50:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/01 23:36:32 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define INVALID_MAP_LEFT "Invalid map first column must be 1"
# define EMPTY_FILE "Empty file"
# define WRONG_CUB_TYPE_FILE "Wrong Type of file. Is need a .cub"
# define WRONG_TEXTURE_TYPE_FILE "Wrong Type of file. Is need a .xpm"
# define FILE_NOT_FOUND "File not found"
# define WRONG_ARGUMENTS "Wrong usage, need two arguments: ./cub3d ./pathToMap"
# define TEXTURE_NOT_SPECIFIED "Texture names not specified correctly"
# define RGB_NOT_SPECIFIED "'C' ceilling or 'F' Floor, not specified correctly"
# define WRONG_RGB "Wrong usage of RGB. (0 >= & <=255)"
# define INVALID_MAP "Invalid map"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_state
{
	TEXTURE,
	RGB
}	t_state;

typedef struct s_utils
{
	char	***texture;
}	t_utils;

typedef struct s_rgb
{
	int	green;
	int	red;
	int	blue;
}	t_rgb;

typedef struct s_mode
{
	t_utils	utils;
	t_rgb	cell_rgb;
	t_rgb	floor_rgb;
	char	*map_path;
	int		map_fd;
	char	**all_map;
	char	**aux_color;
	int		texture_no;
	int		texture_so;
	int		texture_ea;
	int		texture_we;
	int		rgb_f;
	int		rgb_c;

	//map
	int		map_start_in;
	int		map_end_in;
	int		letter_map_found;
	int		found_letter;
}	t_mode;

#endif
