/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:18:12 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/09 00:13:55 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	valid_comma_end(t_mode *mode, char *str);

void	valid_comma(t_mode *mode, char *str, int comma, int i)
{
	while(str[++i] != '\0')
	{
		if (str[i] == ',')
			comma++;
	}
	if (comma != 2)
	{
		ft_free_null(&str);
		close_all(mode, WRONG_RGB);
	}
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		if (str[i] == ',')
		{
			ft_free_null(&str);
			close_all(mode, WRONG_RGB);
		}
	}
	valid_comma_end(mode, str);
}

static void	valid_comma_end(t_mode *mode, char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ' ')
			continue ;
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		if (str[i] == ',')
		{
			ft_free_null(&str);
			close_all(mode, WRONG_RGB);
		}
		i--;
	}
	ft_free_null(&str);
}

int	rgb_aux_separate_ptr(char *str)
{
	if (ft_strlen(str) == 1)
	{
		if (str[0] == ',' || str[0] == 'F' || str[0] == 'C')
			return (true);
	}
	return (false);
}

void	rgb_exists(t_mode *m)
{
	int	i;

	i = 0;
	while (i < m->map_start_in)
	{
		if (skip_space_cmp(m->map_file[i], "F ", 2) == 0)
		{
			valid_comma(m, ft_strtrim(m->map_file[i], "F"), 0, -1);
			look_for_duplicate(m, "F ", i + 1);
			m->rgb_f = 1;
		}
		if (skip_space_cmp(m->map_file[i], "C ", 2) == 0)
		{
			valid_comma(m, ft_strtrim(m->map_file[i], "C"), 0, -1);
			look_for_duplicate(m, "C ", i + 1);
			m->rgb_c = 1;
		}
		i++;
	}
	if (m->rgb_c == 0 || m->rgb_f == 0 || m->ht == 1)
		close_all(m, RGB_NOT_SPECIFIED);
}
