/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:35:40 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 10:43:17 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static unsigned int	get_color(t_data *data, int x, int y);
static void	sprites(t_data *img, void *mlx, char *path);
static uint32_t	*get_texture_buffer(t_data *img);

void	start_textures(t_mode *mode)
{
	sprites(&mode->sprites.no, mode->mlx.mlx, mode->texture_path[0][1]);
	sprites(&mode->sprites.so, mode->mlx.mlx, mode->texture_path[1][1]);
	sprites(&mode->sprites.we, mode->mlx.mlx, mode->texture_path[2][1]);
	sprites(&mode->sprites.ea, mode->mlx.mlx, mode->texture_path[3][1]);
	mode->textures[0] = get_texture_buffer(&mode->sprites.no);
	mode->textures[1] = get_texture_buffer(&mode->sprites.so);
	mode->textures[2] = get_texture_buffer(&mode->sprites.we);
	mode->textures[3] = get_texture_buffer(&mode->sprites.ea);
}

static unsigned int	get_color(t_data *data, int x, int y)
{
	char *color;
	color = data->addr + (y * data->l_len + x * (data->bpp / 8));
	return (*(unsigned int *)color);
}

static uint32_t	*get_texture_buffer(t_data *img)
{
	int x;
	int y;
	uint32_t *buf;

	buf = ft_calloc(TEXTURE_WIDTH * TEXTURE_HEIGHT, sizeof(uint32_t *));
	x = -1;
	while (++x < TEXTURE_HEIGHT)
	{
		y = -1;
		while (++y < TEXTURE_WIDTH)
		{
			buf[(TEXTURE_WIDTH * y) + x] = (uint32_t)get_color(img, x, y);
		}
	}
	return (buf);
}

static void	sprites(t_data *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x, &img->pos.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len,
			&img->endian);
}
