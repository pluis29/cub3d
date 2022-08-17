/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:45:55 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/17 11:19:50 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	texture_valid_path_and_empty(t_mode *mode);
static void	texture_exists(t_mode *m, int i);
static void	texture_extension(t_mode *mode);

void	find_texture(t_mode *mode, int i)
{
	texture_exists(mode, 0);
	if (mode->ea == 0 || mode->no == 0 || mode->so == 0 || mode->we == 0
		|| mode->ht == 1)
		close_all(mode, TEXTURE_NOT_SPECIFIED);
	mode->temp_texture = (char ***)ft_calloc(5, sizeof(char **));
	while (i < mode->map_start_in)
	{
		if (skip_space_cmp(mode->map_file[i], "NO ", 3) == 0)
			mode->temp_texture[0] = ft_split(mode->map_file[i], ' ');
		if (skip_space_cmp(mode->map_file[i], "SO ", 3) == 0)
			mode->temp_texture[1] = ft_split(mode->map_file[i], ' ');
		if (skip_space_cmp(mode->map_file[i], "WE ", 3) == 0)
			mode->temp_texture[2] = ft_split(mode->map_file[i], ' ');
		if (skip_space_cmp(mode->map_file[i], "EA ", 3) == 0)
			mode->temp_texture[3] = ft_split(mode->map_file[i], ' ');
		i++;
	}
	texture_extension(mode);
}

static void	texture_extension(t_mode *mode)
{
	int	i;

	i = 0;
	while (mode->temp_texture[i] != NULL)
	{
		if (ft_cmp_by_start(mode->temp_texture[i][1], ".xpm",
			(ft_strlen(mode->temp_texture[i][1]) - 4)) != 0)
			close_all(mode, WRONG_TEXTURE_TYPE_FILE);
		i++;
	}
	texture_valid_path_and_empty(mode);
}

static void	texture_valid_path_and_empty(t_mode *mode)
{
	int		i;
	int		temp_fd;
	int		temp_read;
	char	c;

	i = 0;
	while (mode->temp_texture[i] != NULL)
	{
		temp_fd = open(mode->temp_texture[i][1], O_RDONLY);
		if (temp_fd == -1)
		{
			close(temp_fd);
			close_all(mode, XMP_FILE_NOT_FOUND);
		}
		temp_read = read(temp_fd, &c, 1);
		close(temp_fd);
		if (temp_read <= 0)
			close_all(mode, EMPTY_TEXTURE);
		i++;
	}
}

static void	texture_exists(t_mode *m, int i)
{
	while (i < m->map_start_in)
	{
		if (skip_space_cmp(m->map_file[i], "NO ", 3) == 0)
		{
			look_for_duplicate(m, "NO ", i + 1);
			m->no = 1;
		}
		if (skip_space_cmp(m->map_file[i], "SO ", 3) == 0)
		{
			look_for_duplicate(m, "SO ", i + 1);
			m->so = 1;
		}
		if (skip_space_cmp(m->map_file[i], "WE  ", 3) == 0)
		{
			look_for_duplicate(m, "WE ", i + 1);
			m->we = 1;
		}
		if (skip_space_cmp(m->map_file[i], "EA ", 3) == 0)
		{
			look_for_duplicate(m, "EA ", i + 1);
			m->ea = 1;
		}
		i++;
	}
}
