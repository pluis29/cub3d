/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:42:43 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/17 11:41:02 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_lenght(t_mode *mode, float line);

int	is_inside_map(t_mode *mode, float x, float y)
{
	if (x >= 0 && x <= get_lenght(mode, y) * TILE && y >= 0
		&& y <= mode->map_size.height * TILE)
		return (true);
	else
		return (false);
}

int	has_wall_at(t_mode *mode, float x, float y)
{
	int	map_grid_indexx;
	int	map_grid_indexy;

	if (x < 0 || x >= get_lenght(mode, y) * TILE || y < 0
		|| y >= mode->map_size.height * TILE)
		return (false);
	map_grid_indexx = floor(x / TILE);
	map_grid_indexy = floor(y / TILE);
	return (mode->blueprint[map_grid_indexy][map_grid_indexx] != '0');
}

static int	get_lenght(t_mode *mode, float line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE)
		> mode->map_size.height)
		return (0);
	else
		return ((int)ft_strlen(mode->blueprint[(int)floor(line / TILE)]));
}
