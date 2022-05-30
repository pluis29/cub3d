/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:36:09 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/29 16:14:50 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_double_ptr(char **str)
{
	int	count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count])
		free(str[count++]);
	free(str);
	return (NULL);
}
