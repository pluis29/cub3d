/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_enviroments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 07:56:28 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/04 09:40:16 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start_enviroments(t_mode *mode)
{
	double	fov;

	//fov = 60 * (PI / 180);
	/* mode->dist_proj_plane = ((WIDTH / 2) / tan(fov / 2)); //importar math.h */
	start_player_variables(mode);
}
