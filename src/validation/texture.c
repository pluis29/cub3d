/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:45:55 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/03 18:56:38 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	texture_valid_path_and_empty(t_mode *mode);
static void	find_texture_cont(t_mode *mode, int i);
static void	texture_extension(t_mode *mode);

void	find_texture(t_mode *mode, int i)
{
	mode->temp_texture = (char ***)ft_calloc(5, sizeof(char **));
	while (i < mode->map_start_in)
	{
		if (ft_memcmp(mode->map_file[i], "NO ", 3) == 0 && mode->no == 0)
		{
			look_for_duplicate(mode, "NO ", i + 1);
			mode->temp_texture[0] = ft_split(mode->map_file[i], ' ');
			mode->no = 1;
		}
		if (ft_memcmp(mode->map_file[i], "SO ", 3) == 0 && mode->so == 0)
		{
			look_for_duplicate(mode, "SO ", i + 1);
			mode->temp_texture[1] = ft_split(mode->map_file[i], ' ');
			mode->so = 1;
		}
		i++;
	}
	find_texture_cont(mode, 0);
}

static void	find_texture_cont(t_mode *mode, int i)
{
	while (i < mode->map_start_in)
	{
		if (ft_memcmp(mode->map_file[i], "WE ", 3) == 0)
		{
			look_for_duplicate(mode, "WE ", i + 1);
			mode->temp_texture[2] = ft_split(mode->map_file[i], ' ');
			mode->we = 1;
		}
		if (ft_memcmp(mode->map_file[i], "EA ", 3) == 0)
		{
			look_for_duplicate(mode, "EA ", i + 1);
			mode->temp_texture[3] = ft_split(mode->map_file[i], ' ');
			mode->ea = 1;
		}
		i++;
	}
	if (mode->ea == 0 || mode->no == 0
		|| mode->so == 0 || mode->we == 0)
		close_all(mode, TEXTURE_NOT_SPECIFIED);
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
