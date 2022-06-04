/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:18:12 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/04 19:29:14 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	valid_comma_end(t_mode *mode, char *str);

void	valid_comma(t_mode *mode, char *str)
{
	int	comma;
	int	i;

	comma = 0;
	i = -1;
	printf("%s\n",str);
	while(str[++i] != '\0')
	{
		if (str[i] == ',')
			comma++;
	}
	if (comma != 2)
		close_all(mode, WRONG_RGB);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		if (str[i] == ',')
			close_all(mode, WRONG_RGB);
	}
	valid_comma_end(mode, str);
}

static void	valid_comma_end(t_mode *mode, char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ' ')
			continue ;
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		if (str[i] == ',')
			close_all(mode, WRONG_RGB);
		i--;
	}
}
