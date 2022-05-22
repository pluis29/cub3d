/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:29:22 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/19 20:48:55 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_transfer(char **plus, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*plus)[i] != '\n' && (*plus)[i] != '\0')
		i++;
	if ((*plus)[i] == '\0')
	{
		*line = ft_strdup(*plus);
		if (*plus != NULL)
		{
			free(*plus);
			*plus = NULL;
		}
		return (0);
	}
	*line = ft_substr(*plus, 0, i);
	tmp = ft_strdup((*plus) + i + 1);
	free(*plus);
	*plus = tmp;
	return (1);
}

static int	ft_guide(int index, char **plus, char **line)
{
	if (index < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	else if (index == 0 && *plus == NULL )
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_transfer(plus, line));
}

int	ft_get_next_line(int fd, char **line)
{
	t_variable	vr;
	static char	*plus;

	vr.buf = (char *)malloc(BUFFER_SIZE + 1);
	if (vr.buf == NULL)
		return (-1);
	vr.index = read(fd, vr.buf, BUFFER_SIZE);
	while (vr.index > 0)
	{
		vr.buf[vr.index] = '\0';
		if (plus == NULL)
			plus = ft_strdup(vr.buf);
		else
		{
			vr.tmp = ft_strjoin(plus, vr.buf);
			free(plus);
			plus = vr.tmp;
		}
		if (ft_strchr(plus, '\n'))
			break ;
		vr.index = read(fd, vr.buf, BUFFER_SIZE);
	}
	free(vr.buf);
	return (ft_guide(vr.index, &plus, line));
}
