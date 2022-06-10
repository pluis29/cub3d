/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:00:26 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/09 00:13:27 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_veracity(char *s, int posi);

int	skip_space_cmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;
	size_t			p;

	i = 0;
	p = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[p] == ' ')
		p++;
	while (n--)
	{
		if (ss1[p] != ss2[i])
			return (ss1[p] - ss2[i]);
		i++;
		p++;
	}
	return (0);
}

void	look_for_trash(t_mode *mode)
{
	int	i;
	int	posi;

	i = 0;
	while (i < mode->map_start_in)
	{
		posi = 0;
		if (mode->map_file[i][0] == ' ')
		{
			while (mode->map_file[i][posi] == ' ')
				posi++;
			if (check_veracity(mode->map_file[i], posi) == false)
				close_all(mode, INVALID_ELEMENT);
		}
		else
		{
			if(check_veracity(mode->map_file[i], 0) == false)
				close_all(mode, INVALID_ELEMENT);
		}
		i++;
	}
}

void	look_for_duplicate(t_mode *mode, char *target, int i)
{
	while (i < mode->map_start_in)
	{
		if (ft_memcmp(mode->map_file[i], target, ft_strlen(target)) == 0)
			mode->ht = 1;
			/* close_all(mode, SAME_ELEMENT); */
		i++;
	}
}

void	check_end_of_file(t_mode *mode)
{
	int		cpy_end_map;
	char	c;

	cpy_end_map = mode->map_end_in;
	while (mode->map_file[++cpy_end_map] != NULL)
	{
		c = mode->map_file[cpy_end_map][0];
		if (c == 0 || c == '\0' || c == EOF || c == '\n')
			continue ;
		else
			close_all(mode, END_WITH_INVALID);
	}
}

static int	check_veracity(char *s, int posi)
{
	if (s[posi] == 'F' && s[posi + 1] == ' ')
		return (true);
	if (s[posi] == 'C' && s[posi + 1] == ' ')
		return (true);
	if (s[posi] == 'N' && s[posi + 1] == 'O' && s[posi + 2] == ' ')
		return (true);
	if (s[posi] == 'S' && s[posi + 1] == 'O' && s[posi + 2] == ' ')
		return (true);
	if (s[posi] == 'W' && s[posi + 1] == 'E' && s[posi + 2] == ' ')
		return (true);
	if (s[posi] == 'E' && s[posi + 1] == 'A' && s[posi + 2] == ' ')
		return (true);
	if (posi == 0)
		if (s[0] == '\0')
			return (true);
	return (false);
}
