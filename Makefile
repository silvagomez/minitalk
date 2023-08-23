# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsilva-g <dsilva-g@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 00:04:57 by dsilva-g          #+#    #+#              #
#    Updated: 2023/08/23 10:55:26 by dsilva-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C			:=	client
NAME_S			:=	server
NAME_CBONUS		:=	client_bonus
NAME_SBONUS		:=	server_bonus

#------------------------------------------------------------------------------#
#   INGREDIENTS                                                                #
#------------------------------------------------------------------------------#

CC				:=	cc
#CFLAGS			:=	-Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS			:=	-Wall -Wextra -Werror

INCLUDE_PATH	:=	include/
INCLUDE			:=	$(INCLUDE_PATH)minitalk.h
INCLUDE_BPATH	:=	include_bonus/
INCLUDE_B		:=	$(INCLUDE_BPATH)minitalk_bonus.h

LIBFT_PATH		:=	libft/
LIBFT			:=	$(LIBFT_PATH)libft.a

SRC_PATH		:=	src/
SRC_C			:=	client.c
SRC_C			:=	$(SRC_C:%=$(SRC_PATH)%)
SRC_S			:=	server.c
SRC_S			:=	$(SRC_S:%=$(SRC_PATH)%)

SRC_BPATH		:=	src_bonus/
SRC_CBONUS		:=	client_bonus.c minitalk_utils_bonus.c
SRC_CBONUS		:=	$(SRC_CBONUS:%=$(SRC_BPATH)%)
SRC_SBONUS		:=	server_bonus.c
SRC_SBONUS		:=	$(SRC_SBONUS:%=$(SRC_BPATH)%)

OBJ_PATH		:=	obj/
OBJ_C			:=	$(SRC_C:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
OBJ_S			:=	$(SRC_S:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
OBJ_BPATH		:=	obj_bonus/
OBJ_CBONUS		:=	$(SRC_CBONUS:$(SRC_BPATH)%.c=$(OBJ_BPATH)%.o)
OBJ_SBONUS		:=	$(SRC_SBONUS:$(SRC_BPATH)%.c=$(OBJ_BPATH)%.o)

#------------------------------------------------------------------------------#
#   UTENSILS                                                                   #
#------------------------------------------------------------------------------#

RM				:=	rm
RMFLAG			:=	-fr

DIR_DUP			=	mkdir -p $(@D)

#------------------------------------------------------------------------------#
#   RECIPES                                                                    #
#------------------------------------------------------------------------------#

all				:	$(NAME_C) $(NAME_S)

$(NAME_C)		:	$(OBJ_C) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)
					@echo "$(MAGENTA)File $(NAME_C)$(GREEN) compiled!$(WHITE)"

$(NAME_S)		:	$(OBJ_S) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)
					@echo "$(MAGENTA)File $(NAME_S)$(GREEN) compiled!$(WHITE)"

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
				  	$(DIR_DUP)
					$(CC) $(CFLAGS) -I $(INCLUDE_PATH) -c $< -o $@

bonus			:	$(NAME_CBONUS) $(NAME_SBONUS)

$(NAME_CBONUS)	:	$(OBJ_CBONUS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_CBONUS) $(LIBFT) -o $(NAME_CBONUS)
					@echo "$(MAGENTA)File $(NAME_CBONUS)$(GREEN) compiled!$(WHITE)"

$(NAME_SBONUS)	:	$(OBJ_SBONUS) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_SBONUS) $(LIBFT) -o $(NAME_SBONUS)
					@echo "$(MAGENTA)File $(NAME_SBONUS)$(GREEN) compiled!$(WHITE)"

$(OBJ_BPATH)%.o	:	$(SRC_BPATH)%.c
				  	$(DIR_DUP)
					$(CC) $(CFLAGS) -I $(INCLUDE_BPATH) -c $< -o $@

$(LIBFT)		:
					make -C $(LIBFT_PATH) all

clean			:
					make -C $(LIBFT_PATH) clean
					$(RM) $(RMFLAG) $(OBJ_PATH)
					$(RM) $(RMFLAG) $(OBJ_BPATH)
					@echo "$(MAGENTA)Removing fdf files... $(GREEN)done!$(WHITE)"

fclean			:	clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(RMFLAG) $(NAME_C)
					$(RM) $(RMFLAG) $(NAME_S)
					$(RM) $(RMFLAG) $(NAME_CBONUS)
					$(RM) $(RMFLAG) $(NAME_SBONUS)
					@echo "$(MAGENTA)Removing $(NAME) $(GREEN)done!$(WHITE)"

re				:	fclean all

norm			:
					norminette $(LIBFT_PATH) $(SRC_PATH) $(INCLUDE_PATH)

norm_bonus		:	
					norminette $(SRC_BPATH) $(INCLUDE_BPATH)

#------------------------------------------------------------------------------#
#   SPEC                                                                       #
#------------------------------------------------------------------------------#

.PHONY			:	all clean fclean re bonus

#------------------------------------------------------------------------------#
#   COLORS                                                                     #
#------------------------------------------------------------------------------#

GREEN			:=	\033[92m
BLUE			:=	\033[94m
MAGENTA			:=	\033[95m
WHITE			:=	\033[97m

#********************************************************************* END ****#
