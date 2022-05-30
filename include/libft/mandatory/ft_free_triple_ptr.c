/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_triple_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:34:24 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/29 16:15:06 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_triple_ptr(char ***str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		ft_free_double_ptr(str[i++]);
	free(str);
	return (NULL);
}
