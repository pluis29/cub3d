/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:02:59 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/09 19:05:09 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* matem sempre entre 0 e 2 pi */
float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0) //se negativo coloca no lado positivo
		angle = TWO_PI + angle;
	return (angle);
}
