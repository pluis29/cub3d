/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions_I.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:39:27 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/26 15:28:04 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

void	close_all(t_mode *mode, char *reason)
{
	/*
	 * uma funcao para fazer a busca em toda a struct para ninguem ficar de fora verificando se ele ja foi liberado pq as vezes o processo termina antes do free dele e vai ficar alocado melhor ne seu genio
	 *
	 * * free(mode->map_path);
	 * mode->all_map
	 * mode->utils.texture
	 * mode->utils.rgb
	 * mode->aux
	 *
	 *
	 *
	 * SERA??
	 * --rgb
	 * colors
	 * temp
	 *
	 * */
	/* printf("%s\n", reason); */
}
