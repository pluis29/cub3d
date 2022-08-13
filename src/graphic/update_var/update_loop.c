/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:45:45 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/13 12:30:43 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	update_variable(t_mode *mode);
static void	draw_game(t_mode *mode);

int	update_loop(t_mode *mode)
{
	update_variable(mode);
	draw_game(mode);

	return (1);
}

static void	update_variable(t_mode *mode)
{
	player_movement(mode);
	cast_all_rays(mode);
}

static void	draw_game(t_mode *mode)
{

}
