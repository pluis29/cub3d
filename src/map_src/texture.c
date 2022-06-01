/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:56:07 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/01 02:06:27 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	texture_valid_path_and_empty(t_mode *mode);

void	find_texture(t_mode *mode, int i)
{
	while (mode->all_map[i] != NULL && i < mode->map_start_in)
	{
		if (ft_memcmp(mode->all_map[i], "NO ", 3) == 0 && mode->texture_no == 0)
		{
			mode->utils.texture[0] = ft_split(mode->all_map[i], ' ');
			mode->texture_no = 1;
		}
		if (ft_memcmp(mode->all_map[i], "SO ", 3) == 0 && mode->texture_so == 0)
		{
			mode->utils.texture[1] = ft_split(mode->all_map[i], ' ');
			mode->texture_so = 1;
		}
		if (ft_memcmp(mode->all_map[i], "EA ", 3) == 0 && mode->texture_ea == 0)
		{
			mode->utils.texture[2] = ft_split(mode->all_map[i], ' ');
			mode->texture_ea = 1;
		}
		if (ft_memcmp(mode->all_map[i], "WE ", 3) == 0 && mode->texture_we == 0)
		{
			mode->utils.texture[3] = ft_split(mode->all_map[i], ' ');
			mode->texture_we = 1;
		}
		i++;
	}
}

void	texture_extension(t_mode *mode)
{
	int	i;

	i = 0;
	while (mode->utils.texture[i] != NULL)
	{
		if (ft_cmp_by_start(mode->utils.texture[i][1], ".xpm",
				(ft_strlen(mode->utils.texture[i][1]) - 4)) != 0)
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
	while (mode->utils.texture[i] != NULL)
	{
		temp_fd = open(mode->utils.texture[i][1], O_RDONLY);
		if (temp_fd == -1)
		{
			close(temp_fd);
			close_all(mode, FILE_NOT_FOUND);
		}
		temp_read = read(temp_fd, &c, 1);
		close(temp_fd);
		if (temp_read <= 0)
			close_all(mode, EMPTY_FILE);
		i++;
	}
}
