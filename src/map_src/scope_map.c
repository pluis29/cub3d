/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:14:20 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/28 02:13:33 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	verify_map(t_mode *mode, char **av)
{
	mode->map_path = ft_strdup(av[1]);
	if (ft_cmp_byStart(mode->map_path, ".cub",
			(ft_strlen(mode->map_path) - 4)) == true)
		close_all(mode, WRONG_TYPE_FILE);
	map_existance(mode, av);

	mode->utils.texture = ft_calloc(5, sizeof(char *));
	find_texture(mode, 0);
	if (mode->texture_EA == 0 || mode->texture_NO == 0 ||
			mode->texture_SO == 0 || mode->texture_WE == 0)
		printf("alguma textura ta errada\n");

	find_rgb(mode, 0);
	while (1)
		;
	/* texture_exist(mode); */
	/* rgb_validation(mode); */

	return (false);
}

void	map_existance(t_mode *mode, char **av)
{
	char	content;
	int		read_ret;
	int		lines;

	mode->map_fd = open(mode->map_path, O_RDONLY);
	if (mode->map_fd == -1)
		printf("arquivo do mapa nao existe\n");
		/* close_all(mode, FILE_NOT_FOUND); */
	read_ret = read(mode->map_fd, &content, 1);
	if (read_ret == 0)
		printf("mapa vazio\n");
		/* close_all(mode, EMPTY_FILE); */
	lines = 1;
	while (read_ret > 0)
	{
		if (content == '\n' || content == EOF)
			lines++;
		read_ret = read(mode->map_fd, &content, 1);
	}
	close(mode->map_fd);
	read_map_file(mode, lines);
	return ;
}

void	read_map_file(t_mode *mode, int lines)
{
	int	i;

	mode->all_map = ft_calloc((lines + 1),  sizeof(char *));
	mode->map_fd = open(mode->map_path, O_RDONLY);
	i = 0;
	while (ft_get_next_line(mode->map_fd, &mode->all_map[i]))
		i++;
	mode->all_map[i] = NULL;
	close(mode->map_fd);
	return ;
}
