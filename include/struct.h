/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:50:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/23 19:40:58 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define EMPTY_FILE "empty map file"
# define WRONG_TYPE_FILE "Wrong Type of file. Is need .cub"
# define FILE_NOT_FOUND "File not found"

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


	char	**aux;


	int		texture_NO;
	int		texture_SO;
	int		texture_EA;
	int		texture_WE;
	int		rgb_f;
	int		rgb_c;
}	t_mode;

#endif
