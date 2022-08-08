/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:13:26 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 11:23:56 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_pressed(int keycode, t_mode *mode)
{
	if (keycode == ESC)
		close_aplication(mode);
	if (keycode == RIGHT)
		mode->player.side_direction = -1;
	if (keycode == ARROW_RIGHT)
		mode->player.turn_direction = +1;
	if (keycode == LEFT)
		mode->player.side_direction = +1;
	if (keycode == ARROW_LEFT)
		mode->player.turn_direction = -1;
	if (keycode == TOP)
		mode->player.walk_direction = +1;
	if (keycode == DOWN)
		mode->player.walk_direction = -1;
	return (0);
}

int	key_release(int key, t_mode *mode)
{
	if (key == RIGHT)
		mode->player.side_direction = 0;
	if (key == ARROW_RIGHT)
		mode->player.turn_direction = 0;
	if (key == LEFT)
		mode->player.side_direction = 0;
	if (key == ARROW_LEFT)
		mode->player.turn_direction = 0;
	if (key == TOP)
		mode->player.walk_direction = 0;
	if (key == DOWN)
		mode->player.walk_direction = 0;
	return (0);
}
