/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:56 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/13 13:05:46 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEFINES_H
# define DEFINES_H

/* keycode */
# define TOP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ESC 0xff1b

/* proporcao da aplicacao */
# define WIDTH 1200
# define HEIGHT 800

# define TILE 64

# define PI 3.14159265
# define TWO_PI 6.28318530
# define NUM_RAYS WIDTH

/* textures */
# define NO 0
# define EA 1
# define WE 2
# define SO 3
# define NUM_TEXTURES 4
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64







# define WRONG_ARGUMENTS "Wrong usage, need two arguments: ./cub3d ./pathToMap"
/* aux validation */
# define INVALID_ELEMENT "Invalid elements in map file"
# define SAME_ELEMENT "Repeated elements in map file"
# define END_WITH_INVALID "Map file terminated with invalid characters"
/* map file */
# define WRONG_CUB_TYPE_FILE "Wrong Type of file. Is need a .cub"
# define CUB_FILE_NOT_FOUND ".cub file not found"
# define EMPTY_CUB_FILE "Empty .cub file"
/* texture */
# define TEXTURE_NOT_SPECIFIED "Texture names not specified correctly"
# define WRONG_TEXTURE_TYPE_FILE "Wrong Type of file. Is need a .xpm"
# define XMP_FILE_NOT_FOUND ".xmp file not found"
# define EMPTY_TEXTURE "Empty texture file"
/* rgb */
# define RGB_NOT_SPECIFIED "'C' ceilling or 'F' Floor, not specified correctly"
# define WRONG_RGB "Wrong usage of RGB. (0 >= & <=255)"
/* blueprint */
# define INVALID_MAP "Invalid Map/Blueprint"
# define NOT_FOUND_PLAYER "Player not found"
# define INVALID_PLAYER "Cant have more than one player"

#endif
