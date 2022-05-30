/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:49:15 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/29 20:23:13 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "struct.h"
# include "./libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		main(int ac, char **av);
void	close_all(t_mode *mode, char *reason);
void	just_close(t_mode *mode);

/* em criacao */

/* map validations */
int		map_validation(t_mode *mode, char **av);

/* aux */

/* texture and rgb */
void	find_texture(t_mode *mode, int i);
void	texture_existance(t_mode *mode);

void	find_rgb(t_mode *mode, int i);

#endif
