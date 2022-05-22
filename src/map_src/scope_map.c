/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:14:20 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/21 14:17:37 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	verify_map(t_mode *mode, char **av)
{
	mode->map_path = ft_strdup(av[1]);
	printf("%s\n", mode->map_path);
	if (ft_cmp_byStart(mode->map_path, ".cub",
			(ft_strlen(mode->map_path) - 4)) == true)
		close_all(mode, WRONG_TYPE_FILE);
	map_exist(mode, av);

	mode->utils.texture = ft_calloc(5, sizeof(char *));
	find_texture(mode, 0);
	printf("ok\n");
	find_rgb(mode, 0);
	printf("ok 2\n");
	while (1)
		;
	/* texture_exist(mode); */
	/* rgb_validation(mode); */

	return (false);
}
