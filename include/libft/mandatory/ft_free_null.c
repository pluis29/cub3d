/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:27:01 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/26 15:31:13 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_null(char **string)
{
	if (*string)
		free(*string);
	*string = NULL;
	return (NULL);
}

// Set free and null in a char *
// It's necessary pass a char **
// example &str if is a char *
