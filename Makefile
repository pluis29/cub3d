# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 19:39:46 by lpaulo-d          #+#    #+#              #
#    Updated: 2022/06/03 18:25:10 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC			=	src/
P_INCLUDE		=	include/
P_VALIDATION	=	validation/
P_AUX			=	aux/
P_OBJ			=	./obj/

FT				=	ft
P_LIBFT			=	$(P_INCLUDE)libft/

F_AUX			=	exit_and_free.c map_file_aux.c blueprint_aux.c

F_VALIDATION	=	map_file.c texture.c rgb.c blueprint.c
F_SRC			=	main.c $(AUX) $(VALIDATION)

AUX				=	$(addprefix $(P_AUX), $(F_AUX))
VALIDATION		=	$(addprefix $(P_VALIDATION), $(F_VALIDATION))

OBJ				=	$(addprefix $(P_OBJ), $(F_SRC:.c=.o))

NAME			=	cub3D

INC				=	-I $(P_INCLUDE) -I $(P_LIBFT)
LIBFT			=	-L $(P_LIBFT) -l $(FT)
CFLAGS			=	#-Wall -Wextra -Werror #-fsanitize=address
P_GUARD			=	mkdir -p $(@D)
RM				=	rm -rf
CC				=	clang

all:			$(NAME)

$(NAME):		$(OBJ)
				@make --no-print-directory -C $(P_LIBFT)
				@echo '.o created and moved to obj folder'
				@$(CC) $(CFLAGS) -g $(INC) $(OBJ) $(LIBFT) -o $(NAME)
				@echo 'File(cub3d) created'

$(P_OBJ)%.o:	$(P_SRC)%.c
				@$(P_GUARD)
				@$(CC) $(CFLAGS) -g $(INC) -c $< -o $@

val:
				valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes --trace-children=yes --log-file=valgrind-out.txt ./cub3D ./maps_test/valid_map.cub

clean:
				@$(RM) $(P_OBJ)
				@make --no-print-directory -C $(P_LIBFT) clean
				@echo 'All clean dude'

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) vgcore*
				@$(RM) valgrind*
				@make --no-print-directory -C $(P_LIBFT) fclean

re:				fclean all

.PHONY:			all clean fclean
