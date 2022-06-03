/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:50:21 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/03 18:21:11 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_texture
{
	char	*no;
	char	*we;
	char	*ea;
	char	*so;
}	t_texture;

typedef struct s_rgb
{
	int	green;
	int	red;
	int	blue;
}	t_rgb;

typedef struct s_mode
{
	t_rgb		cell_rgb;
	t_rgb		floor_rgb;
	t_texture	texture;

	/* all content from map file*/
	char		**map_file;
	char		***temp_texture;
	char		**temp_color;

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
}	t_mode;

#endif
