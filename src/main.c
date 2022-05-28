/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:21:18 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/28 01:57:44 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char *av[])
{
	t_mode	mode;

	//if (ac != 2)
	ft_memset(&mode, 0, sizeof(mode));
	if (map_validation(&mode, av) == true)
		printf("problema no mapa fechando tudo\n");

	return (0);
}

/*
borda deve ser 1
tamanho do mapa
arquivo existe
arquivo é .cub
mapa vazio
tem player
caracteres validos
texturas
cors
empty line
*/
