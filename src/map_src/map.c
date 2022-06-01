/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:09:41 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/01 02:03:37 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_spaced_line(char *str_map_line);

void	get_first_map_occurrence(t_mode *mode)
{
	while (mode->all_map[mode->map_start_in] != NULL)
	{
		if (mode->all_map[mode->map_start_in][0] == '1')
			break;
		if (mode->all_map[mode->map_start_in][0] == ' ')
			if (check_spaced_line(mode->all_map[mode->map_start_in]) == true)
				break ;
		mode->map_start_in++;
	}
}

static int	check_spaced_line(char *str_map_line)
{
	int i;

	i = 0;
	while (str_map_line[i] == ' ')
		i++;
	if (str_map_line[i] == '1')
		return (true);
	return (false);
}
