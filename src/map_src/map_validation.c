/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:52:28 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/21 20:14:24 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "struct.h"
#include <stdio.h>

void	map_exist(t_mode *mode, char **av)
{
	char	content;
	int		read_ret;
	int		lines;

	mode->map_fd = open(mode->map_path, O_RDONLY);
	printf("to aqui\n");
	if (mode->map_fd == -1)
		printf("fd deu ruim\n");
		/* close_all(mode, FILE_NOT_FOUND); */
	read_ret = read(mode->map_fd, &content, 1);
	if (read_ret == 0)
		close_all(mode, EMPTY_FILE);
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
