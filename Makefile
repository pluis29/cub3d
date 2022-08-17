# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 19:39:46 by lpaulo-d          #+#    #+#              #
#    Updated: 2022/06/10 01:11:16 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC			=	src/
P_INCLUDE		=	include/
P_VALIDATION	=	validation/
P_AUX_V			=	aux_v/
P_GRAPHIC		=	graphic/
P_OBJ			=	./obj/
P_RAYS			=	rays/
P_RENDER		=	render/
P_START_VAR		=	start_var/
P_UPDATE_VAR	=	update_var/
P_UTILS			=	utils/

P_LIBFT			=	$(P_INCLUDE)libft/
P_MLX			=	$(P_INCLUDE)minilibx-linux/

F_RAYS			=	rays_facing.c rays_intersection.c rays_utils.c rays.c
F_RENDER		=	render.c render_utils.c
F_START_VAR		=	start_enviroments.c start_player.c start_texture.c
F_UPDATE_VAR	=	handle_events.c player_movement.c update_loop.c
F_UTILS			=	utils_map.c
F_GRAPHIC		=	$(RAYS) $(RENDER) $(START_VAR) $(UPDATE_VAR) $(UTILS)
F_AUX_V			=	map_file_aux.c blueprint_aux.c rgb_aux.c
F_VALIDATION	=	map_file.c texture.c rgb.c blueprint.c
F_SRC			=	main.c exit_and_free.c $(VALIDATION) $(AUX_V) $(GRAPHIC)

AUX_V			=	$(addprefix $(P_VALIDATION)$(P_AUX_V), $(F_AUX_V))
VALIDATION		=	$(addprefix $(P_VALIDATION), $(F_VALIDATION))
RAYS			=	$(addprefix $(P_RAYS), $(F_RAYS))
RENDER			=	$(addprefix $(P_RENDER), $(F_RENDER))
START_VAR		=	$(addprefix $(P_START_VAR), $(F_START_VAR))
UPDATE_VAR		=	$(addprefix $(P_UPDATE_VAR), $(F_UPDATE_VAR))
UTILS			=	$(addprefix $(P_UTILS), $(F_UTILS))
GRAPHIC			=	$(addprefix $(P_GRAPHIC), $(F_GRAPHIC))

OBJ				=	$(addprefix $(P_OBJ), $(F_SRC:.c=.o))

NAME			=	cub3D

INC				=	-I $(P_INCLUDE) -I $(P_LIBFT) -I $(P_MLX)
LIBFT			=	-L $(P_LIBFT) -l ft
MLX				=	-L $(P_MLX) -lmlx -Ilmlx -lXext -lX11 -lm 
CFLAGS			=	-Wall -Wextra -Werror -O3 -g #-fsanitize=address
MFLAGS			=	
P_GUARD			=	mkdir -p $(@D)
RM				=	rm -rf
CC				=	gcc

all:			$(NAME)

$(NAME):		$(OBJ)
				make --no-print-directory -C $(P_LIBFT)
				make --no-print-directory -C $(P_MLX)
				echo '.o created and moved to obj folder'
				$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
				echo 'File(cub3d) created'

$(P_OBJ)%.o:	$(P_SRC)%.c
				$(P_GUARD)
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./cub3D assets/mandatory.cub

clean:
				$(RM) $(P_OBJ)
				make --no-print-directory -C $(P_LIBFT) clean
				make --no-print-directory -C $(P_MLX) clean
				echo 'All clean dude'

fclean:			clean
				$(RM) $(NAME)
				$(RM) vgcore*
				$(RM) valgrind*
				make --no-print-directory -C $(P_LIBFT) fclean

re:				fclean all

.PHONY:			all clean fclean val