/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:12:04 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/26 05:14:46 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (ft_isdigit(*nptr) == 1)
		result = result * 10 + (*nptr++ - '0');
	return (result * sign);
}

/*
	transforma um char numerico em int.

	primeiro while elimina todos os tipos de espacos.
	segundo if se o final for positivo nao mexe no sign se for negativo trans-
forma em negativo para no fim colocar o result em negativo.
	segundo while, transforma em numero, multiplica por 10 para aumentar uma
casa q seria o 0 dps converte o numero e adiciona no lugar do 0 por soma
e o result vai guardando ate retornar.
*/
