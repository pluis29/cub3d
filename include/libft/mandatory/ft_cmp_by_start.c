/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_by_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:47:44 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/29 20:51:16 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_cmp_by_start(const void *string1, const void *string2, int start)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	if (!string1 || !string2)
		return (-1);
	s1 = (unsigned char *)string1;
	s2 = (unsigned char *)string2;
	i = 0;
	while (s1[start] || s2[i])
	{
		if (s1[start] != s2[i])
			return (s1[start] - s2[i]);
		start++;
		i++;
	}
	return (0);
}
