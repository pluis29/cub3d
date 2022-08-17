/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:09:30 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/04 09:39:59 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	save_initial_orientation(t_mode *mode, char facing);
static void	get_player_initial_position(t_mode *mode);
static void	save_initial_angle(t_mode *mode);
static int	read_map(char **blueprint);

void	start_player_variables(t_mode *mode)
{
	ft_memset(&mode->player, 0, sizeof(t_player));
	mode->map_size.height = read_map(mode->blueprint);
	get_player_initial_position(mode);
	mode->player.width = 5;
	mode->player.height = 5;
	mode->player.turn_direction = 0;
	mode->player.walk_direction = 0;
	save_initial_angle(mode);
	mode->player.walk_speed = 10;
	mode->player.turn_speed = 2 * (PI / 180); //in radians
}

static int	read_map(char **blueprint)
{
	int	i;

	if (!blueprint)
		return (0);
	i = 0;
	while (blueprint[i])
		i++;
	return (i);
}

static void	get_player_initial_position(t_mode *mode)
{
	int		y;
	size_t	x;

	y = 0;
	while (y < mode->map_size.height)
	{
		x = 0;
		while (x < ft_strlen(mode->blueprint[y]))
		{
			if (mode->blueprint[y][x] == 'N' || mode->blueprint[y][x] == 'S' ||
				mode->blueprint[y][x] == 'W' || mode->blueprint[y][x] == 'E') // when found we found player position
			{
				mode->player.x = (x * TILE) + 31;
				mode->player.y = (y * TILE) + 32;
				save_initial_orientation(mode, mode->blueprint[y][x]);
				mode->blueprint[y][x] = '0'; // subtitui a letra por zero
				break ;
			}
			x++;
		}
		if (mode->player.x != 0)
			break ;
		y++;
	}
}

static void	save_initial_orientation(t_mode *mode, char facing)
{
	if (facing == 'N')
		mode->player.orientation = NO;
	else if (facing == 'E')
		mode->player.orientation = EA;
	else if (facing == 'W')
		mode->player.orientation = WE;
	else if (facing == 'S')
		mode->player.orientation = SO;
}

static void	save_initial_angle(t_mode *mode)
{
	if (mode->player.orientation == WE)
		mode->player.rotation_angle = TWO_PI / 2;
	else if (mode->player.orientation == EA)
		mode->player.rotation_angle = (TWO_PI * 2) / 2;
	else if (mode->player.orientation == SO)
		mode->player.rotation_angle = PI / 2;
	else if (mode->player.orientation == NO)
		mode->player.rotation_angle = (PI * 3) / 2;
}
