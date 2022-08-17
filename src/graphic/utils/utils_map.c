/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:42:43 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/13 11:48:33 by lpaulo-d         ###   ########.fr       */
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

/**
 * @brief look for wall intersection in specific points
 */
int	has_wall_at(t_mode *mode, float x, float y)
{
	int	map_grid_indexx;
	int	map_grid_indexy;

	if (x < 0 || x >= get_lenght(mode, y) * TILE || y < 0
		|| y >= mode->map_size.height * TILE) // impede de sair do canvas
		return (false);
	map_grid_indexx = floor(x / TILE); //aonde eu estou por tile para falar especificamente
	map_grid_indexy = floor(y / TILE);
	return (mode->blueprint[map_grid_indexy][map_grid_indexx] != '0');//se tem wall true se nao false
}

/**
 * @brief nao entendi muito bem mas parece q super abreviadamente esta vendo se
 *			esta dentro do mapa lateralmente
 */
static int	get_lenght(t_mode *mode, float line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE)
		> mode->map_size.height)
		return (0);
	else
		return ((int)ft_strlen(mode->blueprint[(int)floor(line / TILE)]));
}
