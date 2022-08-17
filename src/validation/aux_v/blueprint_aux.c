/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blueprint_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:16:56 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/17 11:23:31 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_possibility_space(char c, int t_len, int a_len);
static int	check_possibility_zero(char c);

void	set_blueprint(t_mode *mode)
{
	int	i;

	i = 0;
	mode->blueprint = (char **)ft_calloc(mode->map_end_in
			- mode->map_start_in + 2, sizeof(char *));
	while (mode->map_start_in <= mode->map_end_in)
	{
		mode->blueprint[i] = ft_strdup(mode->map_file[mode->map_start_in]);
		i++;
		mode->map_start_in++;
	}
}

void	check_square_space(t_mode *mode, int p, int x)
{
	if (check_possibility_space(mode->map_file[p][x + 1], 0, 0) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode->map_file[p][x - 1], 0, 0) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode->map_file[p - 1][x],
		ft_strlen(mode->map_file[p - 1]), x) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode->map_file[p - 1][x + 1],
		ft_strlen(mode->map_file[p - 1]), x) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode->map_file[p - 1][x - 1],
		ft_strlen(mode->map_file[p - 1]), x) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode->map_file[p + 1][x], 0, 0) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode->map_file[p + 1][x + 1], 0, 0) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode->map_file[p + 1][x - 1], 0, 0) == false)
		close_all(mode, INVALID_MAP);
}

void	check_square_zero(t_mode *mode, int posi, int x)
{
	if (check_possibility_zero(mode->map_file[posi][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode->map_file[posi][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode->map_file[posi - 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode->map_file[posi - 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode->map_file[posi - 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode->map_file[posi + 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode->map_file[posi + 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode->map_file[posi + 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
}

static int	check_possibility_space(char c, int t_len, int a_len)
{
	int	tag_return;

	tag_return = false;
	if (t_len <= a_len)
		return (true);
	if (c == '1' || c == ' ')
		tag_return = true;
	return (tag_return);
}

static int	check_possibility_zero(char c)
{
	int	tag_return;

	tag_return = false;
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		tag_return = true;
	return (tag_return);
}
