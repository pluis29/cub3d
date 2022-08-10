/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:47:39 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 13:19:54 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	has_wall_at(t_mode *mode, float x, float y);
static int	get_lenght(t_mode *mode, float line);

/**
 * @rotation_angle = movimentacao da cabeca do player aonde ele esta olhando
 *					aumenta ou diminui
 *	@move_step = anda para frente ou para tras
 *	@move_step = anda para os lados
 *	@newx @newy = update da localizavao o x seria para frete e para tras e o
 *					y seria para os lados, o valor e calculado pelo move_step e
 *					pegasse a diferenciacao side_step para saber se vai para
 *					o lado
 */
void	player_movement(t_mode *mode)
{
	float	side_step;
	float	move_step;
	float	new_p_x;
	float	new_p_y;

	mode->player.rotation_angle += mode->player.turn_direction *
		mode->player.turn_speed;
	side_step = mode->player.side_direction * mode->player.walk_speed;
	move_step = mode->player.walk_direction * mode->player.walk_speed;

	if (move_step && side_step) //nao sei oq e
	{
		move_step /= 2;
		side_step /= 2;
	}

	new_p_x = mode->player.x + cos(mode->player.rotation_angle) * move_step;
	new_p_y = mode->player.y + sin(mode->player.rotation_angle) * move_step;
	//new_p_x = new_p_x - sin(-mode->player.rotation_angle) * side_step;
	//new_p_y = new_p_y - cos(-mode->player.rotation_angle) * side_step;

	if (!has_wall_at(mode, new_p_x, new_p_y)) //verifica se tem parede antes de mudar os valores
	{
		mode->player.x = new_p_x;
		mode->player.y = new_p_y;
	}
}

static int	has_wall_at(t_mode *mode, float x, float y)
{
	int	map_grid_indexx;
	int	map_grid_indexy;

	if (x < 0 || x >= get_lenght(mode, y) * TILE || y < 0
		|| y >= mode->map_size.height * TILE) // impede de sair do canvas
		return (1);
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
