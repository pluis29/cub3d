/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blueprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:07:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/14 18:47:19 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	map_valid_bottom_and_top_row(t_mode *mode);
static void	map_valid_left_right_column(t_mode *mode);
static void	map_valid_letter(t_mode *mode);
static void	map_valid_middle(t_mode *mode);

void	check_blueprint(t_mode *mode)
{
	map_valid_bottom_and_top_row(mode);
	map_valid_left_right_column(mode);
	map_valid_letter(mode);
	map_valid_middle(mode);
	set_blueprint(mode);
}

static void	map_valid_bottom_and_top_row(t_mode *mode)
{
	int	x;

	x = -1;
	while (mode->map_file[mode->map_start_in][++x] != '\0')
	{
		if (mode->map_file[mode->map_start_in][x] == '1'
				|| mode->map_file[mode->map_start_in][x] == ' ')
			continue;
		else
			close_all(mode, INVALID_MAP);
	}
	x = -1;
	while (mode->map_file[mode->map_end_in][++x] != '\0')
	{
		if (mode->map_file[mode->map_end_in][x] == '1'
				|| mode->map_file[mode->map_end_in][x] == ' ')
			continue ;
		else
			close_all(mode, INVALID_MAP);
	}
}

static void	map_valid_left_right_column(t_mode *mode)
{
	int cpy_start;
	int len;

	cpy_start = mode->map_start_in;
	while (mode->map_file[++cpy_start] != NULL && cpy_start < mode->map_end_in)
	{
		len = ft_strlen(mode->map_file[cpy_start]);
		if (mode->map_file[cpy_start][0] == '1'
				|| mode->map_file[cpy_start][0] == ' ')
		{
			if (mode->map_file[cpy_start][len - 1] == '1'
					|| mode->map_file[cpy_start][len - 1] == ' ')
				continue ;
			else
				close_all(mode, INVALID_MAP);
		}
		else
				close_all(mode, INVALID_MAP);
	}
}

static void	map_valid_letter(t_mode *mode)
{
	int		cpy_start;
	int		x;
	char	c;

	cpy_start = mode->map_start_in;
	while (mode->map_file[++cpy_start] != NULL)
	{
		x = -1;
		while (mode->map_file[cpy_start][++x] != '\0')
		{
			c = mode->map_file[cpy_start][x];
			if (mode->found_letter == 1)
				if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
					close_all(mode, INVALID_PLAYER);
			if (mode->found_letter == 0)
				if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
					mode->found_letter = 1;
		}
	}
	if (mode->found_letter == 0)
		close_all(mode, NOT_FOUND_PLAYER);
}

static void	map_valid_middle(t_mode *mode)
{
	int cpy_start;
	int	len;
	int	x;

	cpy_start = mode->map_start_in;
	while (mode->map_file[++cpy_start] != NULL && cpy_start < mode->map_end_in)
	{
		len = ft_strlen(mode->map_file[cpy_start]);
		x = 0;
		while (mode->map_file[cpy_start][++x] != '\0' && x < (len - 1))
		{
			/* printf("%c", mode->map_file[cpy_start][x]); */
			if (mode->map_file[cpy_start][x] == '1' || mode->map_file[cpy_start][x] == ' ')
				continue ;
			/* else if (mode->map_file[cpy_start][x] == ' ') */
			/* 	check_square_space(mode, cpy_start, x); */
			else if (mode->map_file[cpy_start][x] == '0')
				check_square_zero(mode, cpy_start, x);
			//remover esse daqui OOOOOOO
			else
			{
				mode->player = mode->map_file[cpy_start][x];
				check_square_zero(mode, cpy_start, x);
			}

		}
		/* printf("\n"); */
	}
}
