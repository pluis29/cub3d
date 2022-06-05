/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:41:24 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/04 23:55:21 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_mode	mode;

	ft_memset(&mode, 0, sizeof(mode));
	if (ac != 2)
		close_all(&mode, WRONG_ARGUMENTS);
	map_file_redirect(&mode, av[1]);


	//testes
	//  for (int i=0;mode.map_file[i] != NULL;i++)
	  	//printf("%d | %s\n",i, mode.map_file[i]);
	//printf("\nfile_lines: %d\n",mode.map_end_in);
	//printf("start blueprintf: %d | %s\n",mode.map_start_in, mode.map_file[mode.map_start_in]);
	//printf("end blueprintf: %d | %s\n",mode.map_end_in, mode.map_file[mode.map_end_in]);



	free_struct(&mode);
	exit(EXIT_SUCCESS);
}
