/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:50:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/28 02:23:35 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define EMPTY_FILE "Empty file"
# define WRONG_CUB_TYPE_FILE "Wrong Type of file. Is need a .cub"
# define WRONG_TEXTURE_TYPE_FILE "Wrong Type of file. Is need a .xpm"
# define FILE_NOT_FOUND "File not found"
# define WRONG_ARGUMENTS "Wrong usage, need two arguments: ./cub3d ./pathToMap"
# define TEXTURE_NOT_SPECIFIED "Texture names not specified correctly"
# define RGB_NOT_SPECIFIED "'C' ceilling or 'F' Floor, not specified correctly"
# define WRONG_RGB "Wrong usage of RGB. (0 >= & <=255)"

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


	int		texture_NO;
	int		texture_SO;
	int		texture_EA;
	int		texture_WE;
	int		rgb_f;
	int		rgb_c;
}	t_mode;

#endif
