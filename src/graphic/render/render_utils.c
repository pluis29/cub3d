#include "cub.h"

void	change_color_intesity(uint32_t *color, float factor)
{
	uint32_t	a;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	a = (*color & 0xFF000000);
	r = (*color & 0x00FF0000) * factor;
	g = (*color & 0x0000FF00) * factor;
	b = (*color & 0x000000FF) * factor;
	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}

void	draw_celling(t_mode *mode, t_projection pr)
{
	pr.y = 0;
	while (pr.y < pr.wall_top_pixel)
		my_mlx_pixel_put(&mode->img, pr.x, pr.y++, mode->cell);
}

void	draw_floor(t_mode *mode, t_projection pr)
{
	pr.y = pr.wall_bottom_pixel;
	while (pr.y < HEIGHT)
		my_mlx_pixel_put(&mode->img, pr.x, pr.y++, mode->floor);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
