/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:56:06 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/28 18:12:17 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_rgb	rgb_setup_toStruct(t_mode *mode, int tag);
static void	rgb_separatePtr(t_mode *mode, char ***color, int i, int x, int d);
static void	rgb_validation_Setup_colorsStruct(t_mode *mode);

void	find_rgb(t_mode *mode, int i)
{
	char	***color;

	color = ft_calloc(3, sizeof(char **));
	while(mode->all_map[i] != NULL)
	{
		if (ft_memcmp(mode->all_map[i], "F ", 2) == 0 && mode->rgb_f == 0)
		{
			color[0] = ft_split(mode->all_map[i++], ' ');
			mode->rgb_f = 1;
		}
		if (ft_memcmp(mode->all_map[i], "C ", 2) == 0 && mode->rgb_c == 0)
		{
			color[1] = ft_split(mode->all_map[i++], ' ');
			mode->rgb_c = 1;
		}
		else
			i++;
	}
	if (mode->rgb_c == 0 || mode->rgb_f == 0)
	{
		ft_free_triplePtr(color);
		close_all(mode, RGB_NOT_SPECIFIED);
	}
	rgb_separatePtr(mode, color, 0, 1, 0);
	ft_free_triplePtr(color);
	rgb_validation_Setup_colorsStruct(mode);
}

/**
 * @brief remove comma from string and transform it into a double pointer for
 * easy access and movement.
*/
static void	rgb_separatePtr(t_mode *mode, char ***color, int i, int x, int d)
{
	char ***temp;
	temp = ft_calloc(8, sizeof(char **));//temp q ser 8 pq depende de como preencheram pode acabar indo mais de um ** para o mesmo***
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
	mode->aux_color = (char **)ft_calloc(8, sizeof(char *));
	while (temp[d] != NULL)
	{
		x = 0;
		while (temp[d][x] != NULL)
			mode->aux_color[i++] = ft_strdup(temp[d][x++]);
		d++;
	}
	ft_free_triplePtr(temp);
}

static void	rgb_validation_Setup_colorsStruct(t_mode *mode)
{
	int i;

	i = 1;
	while(mode->aux_color[i] != NULL)
	{
		if (i == 4)
			i = 5;
		if (ft_checkIsNumber(mode->aux_color[i]) == 0)
			close_all(mode, WRONG_RGB);
		i++;
	}
	mode->floor_rgb = rgb_setup_toStruct(mode, 1);
	mode->cell_rgb = rgb_setup_toStruct(mode, 2);
}


/**
 * @brief Set the values in rgb struct respectively
 * @param tag=1 for floor and 2 for ceiling
 */
static t_rgb	rgb_setup_toStruct(t_mode *mode, int tag)
{
	t_rgb	temp_color;

	if (tag == 1)
	{
		temp_color.red = ft_atoi(mode->aux_color[1]);
		temp_color.green = ft_atoi(mode->aux_color[2]);
		temp_color.blue = ft_atoi(mode->aux_color[3]);
	}
	else
	{
		temp_color.red = ft_atoi(mode->aux_color[5]);
		temp_color.green = ft_atoi(mode->aux_color[6]);
		temp_color.blue = ft_atoi(mode->aux_color[7]);
	}
	if (temp_color.red < 0 || temp_color.green < 0 || temp_color.blue < 0
			|| temp_color.red > 255 || temp_color.green > 255
			|| temp_color.blue > 255)
		close_all(mode, WRONG_RGB);
	return (temp_color);
}
