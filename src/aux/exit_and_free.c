/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:10:37 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/31 22:39:21 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_struct(t_mode *mode);

void	close_all(t_mode *mode, char *reason)
{
	free_struct(mode);
	printf("%sERROR%s\n %s -- %sRead the PDF or Documentation%s\n", BRED, RESET
		, reason, BGRN, RESET);
	exit(EXIT_FAILURE);
}

void	just_close(t_mode *mode)
{
	free_struct(mode);
	exit(EXIT_SUCCESS);
}

static void	free_struct(t_mode *mode)
{
	if (mode->utils.texture != NULL)
		ft_free_triple_ptr(mode->utils.texture);
	if (mode->map_path != NULL)
		ft_free_null(&mode->map_path);
	if (mode->all_map != NULL)
		ft_free_double_ptr(mode->all_map);
	if (mode->all_map != NULL)
		ft_free_double_ptr(mode->aux_color);
}
