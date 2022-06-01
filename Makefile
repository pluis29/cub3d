# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 19:39:46 by lpaulo-d          #+#    #+#              #
#    Updated: 2022/05/31 22:11:41 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC			=	src/
P_INCLUDE		=	include/
P_MAP_SRC		=	map_src/
P_AUX			=	aux/
P_OBJ			=	./obj/

FT				=	ft
P_LIBFT			=	$(P_INCLUDE)libft/

F_AUX			=	exit_and_free.c

F_MAP_SRC		=	map_redirect.c texture.c rgb.c map.c
F_SRC			=	main.c $(AUX) $(MAP_SRC)

AUX				=	$(addprefix $(P_AUX), $(F_AUX))
MAP_SRC			=	$(addprefix $(P_MAP_SRC), $(F_MAP_SRC))

OBJ				=	$(addprefix $(P_OBJ), $(F_SRC:.c=.o))

NAME			=	cub3d

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
