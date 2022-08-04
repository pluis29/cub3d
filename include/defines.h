/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:56 by lpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/04 09:25:34 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEFINES_H
# define DEFINES_H


# define WIDTH 1200
# define HEIGHT 800

# define TILE 64

# define PI 3.14159265
# define TWO_PI 6.28318530
# define NUM_RAYS WIDTH

# define NO 0
# define EA 1
# define WE 2
# define SO 3
/* # define NUM_TEXTURES 4 */







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
