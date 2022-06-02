/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:59:51 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/01 23:55:37 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

static void	map_valid_left_right_column(t_mode *mode);
static int	check_possibility_zero(t_mode *mode, char c);
static void	check_square_zero(t_mode *mode, int posi, int x);
static void	map_valid_middle(t_mode *mode);
static void	check_square_space(t_mode *mode, int posi, int x);
static int	check_possibility_space(t_mode *mode, char c);
static void	map_valid_letter(t_mode *mode);
static void	map_valid_bottom_and_top_row(t_mode *mode);

static void	map_valid_letter(t_mode *mode)
{
	int		cpy_start;
	int		x;
	char	c;

	cpy_start = mode->map_start_in;
	while (mode->all_map[++cpy_start] != NULL)
	{
		x = -1;
		while (mode->all_map[cpy_start][++x] != '\0')
		{
			c = mode->all_map[cpy_start][x];
			if (mode->found_letter == 1)
				if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
					close_all(mode, &c);
			if (mode->found_letter == 0)
				if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
					mode->found_letter = 1;
		}
	}
}

static void	map_valid_bottom_and_top_row(t_mode *mode)
{
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

}

void	check_blueprint(t_mode *mode)
{
	map_valid_bottom_and_top_row(mode);
	map_valid_left_right_column(mode);
	map_valid_letter(mode);
	map_valid_middle(mode);
}

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



static void	map_valid_middle(t_mode *mode)
{
	int cpy_start;
	int	len;
	int	x;

	cpy_start = mode->map_start_in;
	while (mode->all_map[++cpy_start] != NULL && cpy_start < mode->map_end_in)
	{
		len = ft_strlen(mode->all_map[cpy_start]);
		x = 0;
		while (mode->all_map[cpy_start][++x] != '\0' && x < (len - 1))
		{
			printf("%c ", mode->all_map[cpy_start][x]);
			if (mode->all_map[cpy_start][x] == '0')
				check_square_zero(mode, cpy_start, x);
			if (mode->all_map[cpy_start][x] == ' ')
				check_square_space(mode, cpy_start, x);
		}
	}
}

static void	check_square_space(t_mode *mode, int posi, int x)
{
	if (check_possibility_space(mode, mode->all_map[posi][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->all_map[posi][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->all_map[posi - 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->all_map[posi - 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->all_map[posi - 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->all_map[posi + 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->all_map[posi + 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_space(mode, mode->all_map[posi + 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
}

static int	check_possibility_space(t_mode *mode, char c)
{
	int	tag_return;

	tag_return = false;
	if (c == '1' || c == ' ' || c == 0)
		tag_return = true;
	return (tag_return);
}

static void	check_square_zero(t_mode *mode, int posi, int x)
{
	if (check_possibility_zero(mode, mode->all_map[posi][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->all_map[posi][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->all_map[posi - 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->all_map[posi - 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->all_map[posi - 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->all_map[posi + 1][x]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->all_map[posi + 1][x + 1]) == false)
		close_all(mode, INVALID_MAP);
	if (check_possibility_zero(mode, mode->all_map[posi + 1][x - 1]) == false)
		close_all(mode, INVALID_MAP);
}

static int	check_possibility_zero(t_mode *mode, char c)
{
	int	tag_return;

	tag_return = false;
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		tag_return = true;
	return (tag_return);
}
