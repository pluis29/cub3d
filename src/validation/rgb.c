/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:55:42 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/03 13:15:26 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

static void		rgb_separate_ptr(t_mode *mode, char ***color, int i, int x);
static void		rgb_validation_setup_colors_struct(t_mode *mode);
static t_rgb	rgb_setup_to_struct(t_mode *mode, int tag);

void	find_rgb(t_mode *mode, int i)
{
	char	***color;

	color = ft_calloc(3, sizeof(char **));
	while (i < mode->map_start_in)
	{
		if (skip_space_cmp(mode->map_file[i], "F ", 2) == 0 && mode->rgb_f == 0)
		{
			look_for_duplicate(mode, "F ", i + 1);
			color[0] = ft_split(mode->map_file[i++], ' ');
			mode->rgb_f = 1;
		}
		if (ft_memcmp(mode->map_file[i], "C ", 2) == 0 && mode->rgb_c == 0)
		{
			look_for_duplicate(mode, "C ", i + 1);
			color[1] = ft_split(mode->map_file[i++], ' ');
			mode->rgb_c = 1;
		}
		else
			i++;
	}
	if (mode->rgb_c == 0 || mode->rgb_f == 0)
	{
		ft_free_triple_ptr(color);
		close_all(mode, RGB_NOT_SPECIFIED);
	}
	rgb_separate_ptr(mode, color, 0, 1);
	rgb_validation_setup_colors_struct(mode);
}


/**
 * @brief remove comma from string and transform it into a double pointer for
 * easy access and movement.
*/
static void	rgb_separate_ptr(t_mode *mode, char ***color, int i, int x)
{
	char	***temp;
	int		d;

	temp = (char ***)ft_calloc(9, sizeof(char **));
	d = 0;
	while (color[i] != NULL)
	{
		x = 0;
		while (color[i][x] != NULL)
			temp[d++] = ft_split(color[i][x++], ',');
		i++;
	}
	x = 0;
	d = 0;
	i = 0;
	mode->temp_color = (char **)ft_calloc(12, sizeof(char *));
	while (temp[d] != NULL)
	{
		x = 0;
		while (temp[d][x] != NULL)
			mode->temp_color[i++] = ft_strdup(temp[d][x++]);
		d++;
	}
	ft_free_triple_ptr(temp);
	ft_free_triple_ptr(color);
}

static void	rgb_validation_setup_colors_struct(t_mode *mode)
{
	int	i;

	i = 1;
	while (mode->temp_color[i] != NULL)
	{
		if (i == 4)
			i = 5;
		if (ft_check_is_number(mode->temp_color[i]) == 0)
			close_all(mode, WRONG_RGB);
		i++;
	}
	if (i != 8)
		close_all(mode, WRONG_RGB);
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
		temp_color.red = ft_atoi(mode->temp_color[1]);
		temp_color.green = ft_atoi(mode->temp_color[2]);
		temp_color.blue = ft_atoi(mode->temp_color[3]);
	}
	else
	{
		temp_color.red = ft_atoi(mode->temp_color[5]);
		temp_color.green = ft_atoi(mode->temp_color[6]);
		temp_color.blue = ft_atoi(mode->temp_color[7]);
	}
	if (temp_color.red < 0 || temp_color.green < 0 || temp_color.blue < 0
		|| temp_color.red > 255 || temp_color.green > 255
		|| temp_color.blue > 255)
		close_all(mode, WRONG_RGB);
	return (temp_color);
}
