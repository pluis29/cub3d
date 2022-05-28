/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:56:07 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/28 02:12:31 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	find_texture(t_mode *mode, int i)
{
	while(mode->all_map[i] != NULL)
	{
		if (ft_memcmp(mode->all_map[i], "NO", 2) == 0 && mode->texture_NO == 0)
		{
			mode->utils.texture[0] = ft_split(mode->all_map[i++], ' ');
			mode->texture_NO = 1;
		}
		if (ft_memcmp(mode->all_map[i], "SO", 2) == 0 && mode->texture_SO == 0)
		{
			mode->utils.texture[1] = ft_split(mode->all_map[i++], ' ');
			mode->texture_SO = 1;
		}
		if (ft_memcmp(mode->all_map[i], "EA", 2) == 0 && mode->texture_EA == 0)
		{
			mode->utils.texture[2] = ft_split(mode->all_map[i++], ' ');
			mode->texture_EA = 1;
		}
		if (ft_memcmp(mode->all_map[i], "WE", 2) == 0 && mode->texture_WE == 0)
		{
			mode->utils.texture[3] = ft_split(mode->all_map[i++], ' ');
			mode->texture_WE = 1;
		}
		else
			i++;
	}
}
