/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blueprint_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:16:56 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/03 18:18:31 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_possibility_space(t_mode *mode, char c);
static int	check_possibility_zero(t_mode *mode, char c);

void	check_square_space(t_mode *mode, int posi, int x)
{
	if (check_possibility_space(mode, mode->map_file[posi][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->map_file[posi][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->map_file[posi - 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->map_file[posi - 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->map_file[posi - 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->map_file[posi + 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->map_file[posi + 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->map_file[posi + 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
}

void	check_square_zero(t_mode *mode, int posi, int x)
{
	if (check_possibility_zero(mode, mode->map_file[posi][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->map_file[posi][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->map_file[posi - 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->map_file[posi - 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->map_file[posi - 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->map_file[posi + 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->map_file[posi + 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->map_file[posi + 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
}

static int	check_possibility_space(t_mode *mode, char c)
{
	int	tag_return;

	tag_return = false;
	if (c == '1' || c == ' ')
		tag_return = true;
	return (tag_return);
}


static int	check_possibility_zero(t_mode *mode, char c)
{
	int	tag_return;

	tag_return = false;
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		tag_return = true;
	return (tag_return);
}
