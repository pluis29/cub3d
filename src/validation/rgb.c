/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:55:42 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/09 00:05:32 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		rgb_separate_ptr(t_mode *mode, int i, int x, int d);
static void		rgb_separate_ptr_cont(t_mode *mode, char ***temp);
static void		rgb_validation_setup_colors_struct(t_mode *mode);
static t_rgb	rgb_setup_to_struct(t_mode *mode, int tag);

void	find_rgb(t_mode *mode, int i)
{
	rgb_exists(mode);
	mode->temp_rgb = ft_calloc(3, sizeof(char **));
	while (i < mode->map_start_in)
	{
		if (skip_space_cmp(mode->map_file[i], "F ", 2) == 0)
			mode->temp_rgb[0] = ft_split(mode->map_file[i++], ' ');
		if (skip_space_cmp(mode->map_file[i], "C ", 2) == 0)
			mode->temp_rgb[1] = ft_split(mode->map_file[i++], ' ');
		else
			i++;
	}
	rgb_separate_ptr(mode, -1, 1, 0);
	rgb_validation_setup_colors_struct(mode);
}


/**
 * @brief remove comma from string and transform it into a double pointer for
 * easy access and movement.
*/
static void	rgb_separate_ptr(t_mode *mode, int i, int x, int d)
{
	char	***temp;

	temp = (char ***)ft_calloc(9, sizeof(char **));
	while (mode->temp_rgb[++i] != NULL)
	{
		x = -1;
		while (mode->temp_rgb[i][++x] != NULL)
		{
			if (rgb_aux_separate_ptr(mode->temp_rgb[i][x]) == true)
					continue ;
			else
				temp[d++] = ft_split(mode->temp_rgb[i][x], ',');
		}
	}
	rgb_separate_ptr_cont(mode,temp);
	ft_free_triple_ptr(temp);
}

static void	rgb_separate_ptr_cont(t_mode *mode, char ***temp)
{
	int	d;
	int	i;
	int	x;

	d = -1;
	i = 0;
	mode->temp_color = (char **)ft_calloc(7, sizeof(char *));
	while (temp[++d] != NULL)
	{
		x = 0;
		while (temp[d][x] != NULL)
		{
			if (i > 5)
			{
				ft_free_triple_ptr(temp);
				close_all(mode, WRONG_RGB);
			}
			mode->temp_color[i++] = ft_strdup(temp[d][x++]);

		}
	}
}

static void	rgb_validation_setup_colors_struct(t_mode *mode)
{
	int	i;

	i = 0;
	while (mode->temp_color[i] != NULL)
	{
		if (ft_check_is_number(mode->temp_color[i]) == 0)
			close_all(mode, WRONG_RGB);
		i++;
	}
	mode->floor_rgb = rgb_setup_to_struct(mode, 1);
	mode->cell_rgb = rgb_setup_to_struct(mode, 2);
}

/**
 * @brief Set the values in rgb struct respectively
 * @param tag=1 for floor and 2 for ceiling
 */
static t_rgb	rgb_setup_to_struct(t_mode *mode, int tag)
{
	t_rgb	temp_color;

	if (tag == 1)
	{
		temp_color.red = ft_atoi(mode->temp_color[0]);
		temp_color.green = ft_atoi(mode->temp_color[1]);
		temp_color.blue = ft_atoi(mode->temp_color[2]);
	}
	else
	{
		temp_color.red = ft_atoi(mode->temp_color[3]);
		temp_color.green = ft_atoi(mode->temp_color[4]);
		temp_color.blue = ft_atoi(mode->temp_color[5]);
	}
	if (temp_color.red < 0 || temp_color.green < 0 || temp_color.blue < 0
		|| temp_color.red > 255 || temp_color.green > 255
		|| temp_color.blue > 255)
		close_all(mode, WRONG_RGB);
	return (temp_color);
}
