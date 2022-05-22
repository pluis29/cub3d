/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:49:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/21 14:17:04 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "struct.h"
# include "./libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>


int	main(int ac, char **av);

/* map validations */
int		verify_map(t_mode *mode, char **av);
void	read_map_file(t_mode *mode, int lines);
void	map_exist(t_mode *mode, char **av);

/* aux */
void	free_null(char **string);

/* em criacao */
void	close_all(t_mode *mode, char *reason);
void	find_texture(t_mode *mode, int i);
void	find_rgb(t_mode *mode, int i);

#endif
