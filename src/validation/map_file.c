/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:49:20 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/10 01:11:39 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	store_map_file(t_mode *mode, int lines, char *path);
static void	path_existance(t_mode *mode, char *path);
static void	get_start_end_from_map(t_mode *mode, int file_lines);
static int	check_spaced_line(char *str_line, int tag);

void	map_file_redirect(t_mode *mode, char *path)
{
	if (ft_cmp_by_start(path, ".cub", ft_strlen(path) - 4) != 0)
		close_all(mode, WRONG_CUB_TYPE_FILE);

	path_existance(mode, path);
	if (mode->map_file[mode->map_start_in + 1] ==  NULL)
		close_all(mode, INVALID_MAP);
	look_for_trash(mode);
	find_texture(mode, 0);
	find_rgb(mode, 0);
	check_end_of_file(mode);
	check_blueprint(mode);
}

static void	path_existance(t_mode *mode, char *path)
{
	char	c;
	int		ret_read;
	int		map_fd;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		close_all(mode, CUB_FILE_NOT_FOUND);
	ret_read = read(map_fd, &c, 1);
	if (ret_read == 0)
		close_all(mode, EMPTY_CUB_FILE);
	while(ret_read > 0)
	{
		if (c == '\n' || c == EOF)
			mode->file_lines++;
		ret_read = read(map_fd, &c, 1);
	}
	close(map_fd);
	store_map_file(mode, mode->file_lines, path);
}

static void	store_map_file(t_mode *mode, int lines, char *path)
{
	int	i;
	int	map_fd;

	mode->map_file = (char **)ft_calloc((lines + 2), sizeof(char *));
	map_fd = open(path, O_RDONLY);
	i = 0;
	while (ft_get_next_line(map_fd, &mode->map_file[i]))
		i++;
	close(map_fd);
	get_start_end_from_map(mode, mode->file_lines);
}

static void	get_start_end_from_map(t_mode *mode, int file_lines)
{
	while (mode->map_file[mode->map_start_in + 1] != NULL)
	{
		if (mode->map_file[mode->map_start_in][0] == '1')
			break;
		if (mode->map_file[mode->map_start_in][0] == '0')
			break;
		if (mode->map_file[mode->map_start_in][0] == ' ')
			if (check_spaced_line(mode->map_file[mode->map_start_in], 1)
					 == true)
				break ;
		mode->map_start_in++;
	}
	while (file_lines >= 0)
	{
		if (mode->map_file[file_lines][0] == '1')
			break;
		if (mode->map_file[file_lines][0] == ' ')
			if (check_spaced_line(mode->map_file[file_lines], 0)
					== true)
				break ;
		file_lines--;
	}
	mode->map_end_in = file_lines;
}

static int	check_spaced_line(char *str_line, int tag)
{
	int i;

	i = 0;
	while (str_line[i] == ' ')
		i++;
	if (tag == 1)
		if (str_line[i] == '0')
			return (true);
	if (str_line[i] == '1')
		return (true);
	return (false);
}
