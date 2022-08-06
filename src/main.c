/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:41:24 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 10:44:44 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	start_game(t_mode *mode);

int	main(int ac, char **av)
{
	t_mode	mode;

	ft_memset(&mode, 0, sizeof(mode));
	if (ac != 2)
		close_all(&mode, WRONG_ARGUMENTS);
	map_file_redirect(&mode, av[1]);

	/* mlx_shit */
	/* void	*mlx; */
	/* void	*mlx_win; */
	/* t_data	img; */
	/* t_rect rect; */

	/* printf("%s\n",mode.blueprint[0]); */
	/* read_map(&mode); */
	/* mlx = mlx_init(); */
	/* mlx_win = mlx_new_window(mlx, mode.cols*32, mode.rows*32, "Hello world!"); */
	/* img.img = mlx_new_image(mlx, mode.cols*32, mode.rows*32); */
	/* img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, */
	/* 							&img.endian); */
	/* int	i=0; */
	/* int	x=0; */
	/* while (mode.blueprint[i] != NULL) */
	/* { */
	/* 	x=0; */
	/* 	while (mode.blueprint[i][x] != '\0') */
	/* 	{ */
	/* 		if (mode.blueprint[i][x] == '1') */
	/* 			draw_square(i,x,&img, 0x00FF0000); */
	/* 		else if (mode.blueprint[i][x] == ' ') */
	/* 		{ */
	/* 			x++; */
	/* 			continue ; */
	/* 		} */
	/* 		else if (mode.blueprint[i][x] == mode.player) */
	/* 			draw_square(i,x,&img,0xFF00FF); */
	/* 		else */
	/* 			draw_empty_square(i,x,&img, 0xFF00FF); */
	/* 		x++; */
	/* 	} */
	/* 	i++; */
	/* } */
	/* while (mode.blueprint[i][x] != '\0') */
	/* { */
	/* 	if (mode.blueprint[i][x] == '1') */
	/* 	{ */

	/* 		draw_square(0,x,&img); */
	/* 	} */
	/* 	x++; */
	/* } */
	/* draw_square(0,0,&img); */
	/* draw_square(4,0,&img); */
	/* rect.x =0; */
	/* rect.y=0; */
	/* rect.width=30; */
	/* rect.height=30; */
	/* rect.color = 0xFF00FF; */
	/* draw_rect(&img,rect); */
	/* rect.x =0; */
	/* rect.y=300; */
	/* rect.color = 0x00FF0000; */
	/* draw_rect(&img,rect); */
	/* draw_rect(0,4,&img); */
	/* mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); */
	/* mlx_loop(mlx); */

	start_game(&mode);

	free_struct(&mode);
	exit(EXIT_SUCCESS);
}


/**
 * @brief start mlx and game enviroments
 */
static void	start_game(t_mode *mode)
{
	t_data	img_p;

	ft_bzero(&img_p, sizeof(t_data));
	mode->mlx.mlx = mlx_init();
	mode->mlx.win = mlx_new_window(mode->mlx.mlx, WIDTH, HEIGHT, "Cub3D");

	mode->img.img = mlx_new_image(mode->mlx.mlx, WIDTH, HEIGHT);
	mode->img.addr = mlx_get_data_addr(mode->img.img, &mode->img.bpp,
			&mode->img.l_len, &mode->img.endian);

	start_enviroments(mode);

	mlx_hook(mode->mlx.win, 17, 0, close_aplication, (void *)mode);
	mlx_hook(mode->mlx.win, 2, 1L << 0, key_pressed, (void *)mode);
	mlx_hook(mode->mlx.win, 3, 1L << 1, key_release, (void *)mode);
	mlx_loop_hook(mode->mlx.mlx, update_loop, (void *)mode);
	mlx_loop(mode->mlx.mlx);
}

// static void	draw_empty_square(int y,int x,t_data *img, int cor)
// {
// 	x*=32;
// 	y*=32;
// 	int	i=0;
// 	int	p=0;
// 	int linha = y;
// 	int coluna;
// 	coluna = x;
// 	while (i < 32)
// 	{
// 		p=0;
// 		if (i ==0||i==31)
// 		{
// 			while (p<32)
// 			{
// 				my_mlx_pixel_put(img, coluna,linha, cor);
// 				coluna++;
// 				p++;
// 			}
// 		}
// 		coluna = x;
// 		my_mlx_pixel_put(img, coluna,linha, cor);
// 		my_mlx_pixel_put(img, coluna+32,linha, cor);
// 		linha++;
// 		i++;
// 	}
// }

// static void draw_square(int	y, int x, t_data *img, int	cor)
// {
// 	x *= 32;
// 	y *= 32;
// 	int linha = y;
// 	int coluna;
// 	int	i;
// 	int p;
// 	i =0;
// 	while (i < 32)
// 	{
// 		p=0;
// 		coluna = x;
// 		while (p< 32)
// 		{
// 			my_mlx_pixel_put(img, coluna, linha, cor);
// 			coluna++;
// 			p++;
// 		}
// 		linha++;
// 		i++;
// 	}
// }

// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// static void	read_map(t_mode *mode)
// {
// 	int	i=0;
// 	int	x=0;
// 	int actual_line=0;
// 	int line_size=0;

// 	while (mode->blueprint[i] != NULL)
// 	{
// 		actual_line = 0;
// 		while (mode->blueprint[i][x] != '\0')
// 		{
// 			actual_line++;
// 			x++;
// 		}
// 		if (actual_line > line_size)
// 			line_size = actual_line;
// 		i++;
// 	}
// 	mode->rows = i;
// 	mode->cols = line_size;
// }
