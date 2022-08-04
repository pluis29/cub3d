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

P_LIBFT			=	$(P_INCLUDE)libft/
P_MLX			=	$(P_INCLUDE)minilibx-linux/

F_AUX_V			=	exit_and_free.c map_file_aux.c blueprint_aux.c rgb_aux.c

F_GRAPHIC		=	start_enviroments.c start_player.c start_texture.c
F_VALIDATION	=	map_file.c texture.c rgb.c blueprint.c
F_SRC			=	main.c $(VALIDATION) $(AUX_V) $(GRAPHIC)

AUX_V			=	$(addprefix $(P_VALIDATION)$(P_AUX_V), $(F_AUX_V))
VALIDATION		=	$(addprefix $(P_VALIDATION), $(F_VALIDATION))
GRAPHIC			=	$(addprefix $(P_GRAPHIC), $(F_GRAPHIC))

OBJ				=	$(addprefix $(P_OBJ), $(F_SRC:.c=.o))

NAME			=	cub3D

INC				=	-I $(P_INCLUDE) -I $(P_LIBFT) -I $(P_MLX)
LIBFT			=	-L $(P_LIBFT) -l ft
MLX				=	-L $(P_MLX) -lmlx -Ilmlx -lXext -lX11 -lm 
CFLAGS			=	#-Wall -Wextra -Werror #-fsanitize=address
MFLAGS			=	
P_GUARD			=	mkdir -p $(@D)
RM				=	rm -rf
CC				=	clang



all:			$(NAME)

$(NAME):		$(OBJ)
				@make --no-print-directory -C $(P_LIBFT)
				@make --no-print-directory -C $(P_MLX)
				@echo '.o created and moved to obj folder'
				@$(CC) $(CFLAGS) -O3 -g $(INC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
				@echo 'File(cub3d) created'

$(P_OBJ)%.o:	$(P_SRC)%.c
				@$(P_GUARD)
				@$(CC) $(CFLAGS) -g $(INC) -c $< -o $@

val:
				valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes --trace-children=yes --log-file=valgrind-out.txt ./cub3D ./maps_test/valid_map.cub

clean:
				@$(RM) $(P_OBJ)
				@make --no-print-directory -C $(P_LIBFT) clean
				@make --no-print-directory -C $(P_MLX) clean
				@echo 'All clean dude'

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) vgcore*
				@$(RM) valgrind*
				@make --no-print-directory -C $(P_LIBFT) fclean

re:				fclean all

.PHONY:			all clean fclean
