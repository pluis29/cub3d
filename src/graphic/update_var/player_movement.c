/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:47:39 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/13 11:46:44 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	new_p_x = new_p_x - sin(-mode->player.rotation_angle) * side_step;
	new_p_y = new_p_y - cos(-mode->player.rotation_angle) * side_step;

	if (!has_wall_at(mode, new_p_x, new_p_y)) //verifica se tem parede antes de mudar os valores
	{
		mode->player.x = new_p_x;
		mode->player.y = new_p_y;
	}
}
