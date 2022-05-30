/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:14:20 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/29 20:50:20 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	read_map_file(t_mode *mode, int lines);
static void	map_existance(t_mode *mode, char **av);

int	map_validation(t_mode *mode, char **av)
{
	mode->map_path = ft_strdup(av[1]);
	if (ft_cmp_by_start(mode->map_path, ".cub",
			(ft_strlen(mode->map_path) - 4)) != 0)
		close_all(mode, WRONG_CUB_TYPE_FILE);
	map_existance(mode, av);
	mode->utils.texture = ft_calloc(5, sizeof(char *));
	find_texture(mode, 0);
	if (mode->texture_ea == 0 || mode->texture_no == 0
		|| mode->texture_so == 0 || mode->texture_we == 0)
		close_all(mode, TEXTURE_NOT_SPECIFIED);
	texture_existance(mode);
	find_rgb(mode, 0);
	while (1)
		;
	return (false);
}

static void	map_existance(t_mode *mode, char **av)
{
	char	content;
	int		read_ret;
	int		lines;

	mode->map_fd = open(mode->map_path, O_RDONLY);
	if (mode->map_fd == -1)
		close_all(mode, FILE_NOT_FOUND);
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

static void	read_map_file(t_mode *mode, int lines)
{
	int	i;

	mode->all_map = ft_calloc((lines + 1), sizeof(char *));
	mode->map_fd = open(mode->map_path, O_RDONLY);
	i = 0;
	while (ft_get_next_line(mode->map_fd, &mode->all_map[i]))
		i++;
	mode->all_map[i] = NULL;
	close(mode->map_fd);
	return ;
}
