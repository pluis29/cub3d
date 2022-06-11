/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:41:24 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/11 00:37:36 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* static void	read_map(t_mode *mode); */

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
	/* read_map(&mode); */
	/* int	height = mode.rows * 32; */
	/* int	width = mode.cols * 32; */
	/* mlx = mlx_init(); */
	/* mlx_win = mlx_new_window(mlx, 500, 500, "cub"); */
	/* mlx_loop(mlx); */

	free_struct(&mode);
	exit(EXIT_SUCCESS);
}

/* static void	read_map(t_mode *mode) */
/* { */
/* 	int	i=0; */
/* 	int	x=0; */
/* 	int actual_line=0; */
/* 	int line_size=0; */

/* 	while (mode->blueprint[i] != NULL) */
/* 	{ */
/* 		actual_line = 0; */
/* 		while (mode->blueprint[i][x] != '\0') */
/* 		{ */
/* 			actual_line++; */
/* 			x++; */
/* 		} */
/* 		if (actual_line > line_size) */
/* 			line_size = actual_line; */
/* 		i++; */
/* 	} */
/* 	mode->rows = i; */
/* 	mode->cols = line_size; */
/* } */
