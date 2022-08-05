#include "cub.h"

unsigned int get_color(t_data *data, int x, int y)
{
	char *color;
	color = data->addr + (y * data->l_len + x * (data->bpp / 8));
	return (*(unsigned int *)color);
}

static uint32_t *get_texture_buffer(t_data *img)
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

void sprites(t_data *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x, &img->pos.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_len, &img->endian);
}

void start_textures(t_mode *mode)
{
	sprites(&mode->sprites.no, mode->s_mlx.mlx, mode->texture_path[0][1]);
	sprites(&mode->sprites.so, mode->s_mlx.mlx, mode->texture_path[1][1]);
	sprites(&mode->sprites.we, mode->s_mlx.mlx, mode->texture_path[2][1]);
	sprites(&mode->sprites.ea, mode->s_mlx.mlx, mode->texture_path[3][1]);
	mode->textures[0] = get_texture_buffer(&mode->sprites.no);
	mode->textures[1] = get_texture_buffer(&mode->sprites.so);
	mode->textures[2] = get_texture_buffer(&mode->sprites.we);
	mode->textures[3] = get_texture_buffer(&mode->sprites.ea);
}