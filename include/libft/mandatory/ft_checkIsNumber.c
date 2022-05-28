/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkIsNumber.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:51:32 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/26 15:09:20 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Move into a string looking for only digits
 *
 * @param str - string
 *
 * @return 1 if all number. 0 if have letter
 */
int ft_checkIsNumber(const char *str)
{
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 1)
			str++;
		else
			return (0);
	}
	return (1);
}
