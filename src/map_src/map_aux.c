/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:59:51 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/01 19:53:37 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	map_valid_left_right_column(t_mode *mode);

void	map_valid_bottom_and_top(t_mode *mode)
{
	//busca linear
	int	x;

	x = -1;
	while (mode->all_map[mode->map_start_in][++x] != '\0')
	{
		if (mode->all_map[mode->map_start_in][x] == '1'
				|| mode->all_map[mode->map_start_in][x] == ' ')
			continue;
		else
			close_all(mode, INVALID_MAP);
	}
	x = -1;
	while (mode->all_map[mode->map_end_in][++x] != '\0')
	{
		if (mode->all_map[mode->map_end_in][x] == '1'
				|| mode->all_map[mode->map_end_in][x] == ' ')
			continue ;
		else
			close_all(mode, INVALID_MAP);
	}
	map_valid_left_right_column(mode);
}

//pode ter irregularidades e atrapalhar a validacao
static void	map_valid_left_right_column(t_mode *mode)
{
	int cpy_start;
	int len;

	cpy_start = mode->map_start_in;
	while (mode->all_map[++cpy_start] != NULL && cpy_start < mode->map_end_in)
	{
		len = ft_strlen(mode->all_map[cpy_start]);
		if (mode->all_map[cpy_start][0] == '1'
				|| mode->all_map[cpy_start][0] == ' ')
		{
			if (mode->all_map[cpy_start][len - 1] == '1'
					|| mode->all_map[cpy_start][len - 1] == ' ')
				continue ;
			else
				close_all(mode, INVALID_MAP);
		}
		else
			close_all(mode, INVALID_MAP);
	}
}


/* void	map_valid_middle(t_mode *mode) */
/* { */
/* 	//busca quadrada */
/* } */
