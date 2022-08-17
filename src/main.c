/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:41:24 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/17 11:13:18 by lpaulo-d         ###   ########.fr       */
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
	start_game(&mode);
	free_struct(&mode);
	return (0);
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
