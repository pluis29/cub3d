/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:45:04 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 11:23:16 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	close_all(t_mode *mode, char *reason)
{
	free_struct(mode);
	/* printf("Error\n"); */
	printf("%sError%s\n%s -- %sRead the PDF or Documentation%s\n", BRED, RESET
		, reason, BGRN, RESET);
	exit(EXIT_FAILURE);
}

void	just_close(t_mode *mode)
{
	free_struct(mode);
	exit(EXIT_SUCCESS);
}

int	close_aplication(t_mode *mode)
{
	free_struct(mode);
	free_mlx(mode);
	exit(EXIT_SUCCESS);
}

void	free_struct(t_mode *mode)
{
	if (mode->map_file != NULL)
		ft_free_double_ptr(mode->map_file);
	if (mode->temp_texture != NULL)
		ft_free_triple_ptr(mode->temp_texture);
	if (mode->temp_color != NULL)
		ft_free_double_ptr(mode->temp_color);
	if (mode->temp_rgb != NULL)
		ft_free_triple_ptr(mode->temp_rgb);
	if (mode->blueprint != NULL)
		ft_free_double_ptr(mode->blueprint);
}

void	free_mlx(t_mode *mode)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
		free(mode->textures[i++]);
	mlx_destroy_image(mode->mlx.mlx, mode->img.img);
	mlx_destroy_window(mode->mlx.mlx, mode->mlx.win);
	mlx_destroy_display(mode->mlx.mlx);
	ft_free_void_ptr(&mode->mlx.mlx);
}
