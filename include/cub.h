/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:49:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/10 18:05:24 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "struct.h"
# include "./libft/libft.h"
# include "ansi_color.h"
# include "defines.h"
# include "./minilibx-linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		main(int ac, char **av);

/* em criacao */

/* rgb */
void	valid_comma(t_mode *mode, char *str, int comma, int i);
int		rgb_aux_separate_ptr(char *str);
void	find_rgb(t_mode *mode, int i);
void	rgb_exists(t_mode *m);

/* texture */
void	find_texture(t_mode *mode, int i);

/* map file*/
void	check_square_space(t_mode *mode, int posi, int x);
void	map_file_redirect(t_mode *mode, char *path);

/* blueprint */
void	check_square_zero(t_mode *mode, int posi, int x);
void	check_blueprint(t_mode *mode);
void	set_blueprint(t_mode *mode);

/* aux */
int		skip_space_cmp(const void *s1, const void *s2, size_t n);
void	look_for_duplicate(t_mode *mode, char *target, int i);
void	check_end_of_file(t_mode *mode);
void	look_for_trash(t_mode *mode);

/* aux free */
void	close_all(t_mode *mode, char *reason);
void	free_struct(t_mode *mode);
void	just_close(t_mode *mode);

#endif
