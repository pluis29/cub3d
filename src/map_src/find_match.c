/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:20:05 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/05/23 19:47:18 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
}

void	find_rgb(t_mode *mode, int i)
{
	char	***color;

	/**
	 * cria separa as infos no ** entre ***0e1
	 */
	color = ft_calloc(3, sizeof(char **));
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
	fix_rgb_pointers(mode, color, 0, 1, 0);
	/* free_triple(color); */
	/* send_rgb_struct(mode) */
}


void	fix_rgb_pointers(t_mode *mode, char ***color, int i, int x, int d)
{
	char ***temp;
	temp = ft_calloc(8, sizeof(char **));//temp q ser 8 pq depende de como preencheram pode acabar indo mais de um ** para o mesmo***
	while (color[i] != NULL)
	{
		x = 0;
		while (color[i][x] != NULL)
		{
			/* printf("color content: %s\n", color[i][x]); */
			temp[d++] = ft_split(color[i][x++], ',');
		}
		i++;
	}
	x = 0;
	d = 0;
	i = 0;
	mode->aux = (char **)ft_calloc(8, sizeof(char *));
	while (temp[d] != NULL)
	{
		x=0;
		while (temp[d][x] != NULL)
		{
			/* printf("------content: %s\n", temp[d][x]); */
			mode->aux[i++] = ft_strdup(temp[d][x++]);
		}
		d++;
	}
	/* free_triple(temp); */
	/* for (int p=0; mode->aux[p] != NULL;p++) */
	/* 	printf("foraaaa:   %s\n",mode->aux[p]); */
}



	/* x = 0; */
	/* d = 0; */
	/* while (temp[x] != NULL) */
	/* { */
	/* 	d =0; */
	/* 	while (temp[x][d] != NULL) */
	/* 	{ */
	/* 		printf("x: %d || d: %d || %s\n",x,d, temp[x][d]); */
	/* 		d++; */
	/* 	} */
	/* 	x++; */
	/* } */


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
