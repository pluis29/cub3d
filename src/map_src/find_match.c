/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:20:05 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/21 21:03:19 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"

void	find_texture(t_mode *mode, int i)
{
	while(mode->all_map[i] != NULL)
	{
		if (ft_memcmp(mode->all_map[i], "NO", 2) == 0 && mode->texture_NO == 0)
		{
			mode->utils.texture[0] = ft_split(mode->all_map[i++], ' ');
			mode->texture_NO = 1;
		}
		if (ft_memcmp(mode->all_map[i], "SO", 2) == 0 && mode->texture_SO == 0)
		{
			mode->utils.texture[1] = ft_split(mode->all_map[i++], ' ');
			mode->texture_SO = 1;
		}
		if (ft_memcmp(mode->all_map[i], "EA", 2) == 0 && mode->texture_EA == 0)
		{
			mode->utils.texture[2] = ft_split(mode->all_map[i++], ' ');
			mode->texture_EA = 1;
		}
		if (ft_memcmp(mode->all_map[i], "WE", 2) == 0 && mode->texture_WE == 0)
		{
			mode->utils.texture[3] = ft_split(mode->all_map[i++], ' ');
			mode->texture_WE = 1;
		}
		else
			i++;
	}
	printf("oxi\n");
}

void	find_rgb(t_mode *mode, int i)
{
	char	***color;

	color = ft_calloc(3, sizeof(char *));
	while(mode->all_map[i] != NULL)
	{
		if (ft_memcmp(mode->all_map[i], "F ", 2) == 0 && mode->rgb_f == 0)
		{
			color[0] = ft_split(mode->all_map[i++], ' ');
			mode->rgb_f = 1;
		}
		if (ft_memcmp(mode->all_map[i], "C ", 2) == 0 && mode->rgb_c == 0)
		{
			color[1] = ft_split(mode->all_map[i++], ' ');
			mode->rgb_c = 1;
		}
		else
			i++;
	}
	printf("foi\n");




	char ***temp;
	int	x=1;
	int	d=0;
	temp = ft_calloc(4, sizeof(char *));

	/* ta alocando cada numero no terceiro dimensao e na segunda ta baguncado o printf tem a solucao abaixo */
	while (color[0][x] != NULL)
	{
		temp[d++] = ft_split(color[0][x++], ',');
	}
	printf("foi2\n");
	/* printf("%s\n", temp[0][1]); */


	/* converter para int da para usar soluca de cima para colocar em ponteiro duplo e fica mais facil */
	x=0;
	d=0;
	int c =0;
	char **aqui;
	aqui = ft_calloc(4, sizeof(char*));
	while (temp[d] != NULL)
	{
		x=0;
		while (temp[d][x] != NULL)
		{
			aqui[c++] = ft_strdup(temp[d][x++]);
		}
		d++;
	}
}
	/* printf("foraaaa:   %s\n",aqui[0]); */
	/* printf("foraaaa:   %s\n",aqui[1]); */
	/* printf("foraaaa:   %s\n",aqui[2]); */



	/* int c; */
	/* printf("oi fora\n"); */
	/* while (color[x] != NULL) */
	/* { */
	/* 	printf("oi dentro1\n"); */
	/* 	c =0; */
	/* 	while (color[x][c] != NULL) */
	/* 	{ */
	/* 		printf("x: %d || c: %d || %s\n",x,c, color[x][c]); */
	/* 		c++; */
	/* 	} */
	/* 	x++; */
	/* } */

	/* int	x=0; */
	/* int c; */
	/* printf("oi fora\n"); */
	/* while (mode->utils.texture[x] != NULL) */
	/* { */
	/* 	printf("oi dentro1\n"); */
	/* 	c =0; */
	/* 	while (mode->utils.texture[x][c] != NULL) */
	/* 	{ */
	/* 		printf("x: %d || c: %d || %s\n",x,c, mode->utils.texture[x][c]); */
	/* 		c++; */
	/* 	} */
	/* 	x++; */
	/* } */
	/* int	x=0; */
	/* int c; */
	/* printf("oi fora\n"); */
	/* while (mode->all_map[x] != NULL) */
	/* { */
	/* 	printf("x: %d || %s\n",x,mode->all_map[x]); */
	/* 	x++; */
	/* } */
	/* printf("oi fora2\n"); */
