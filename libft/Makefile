# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 10:20:21 by dsilva-g          #+#    #+#              #
#    Updated: 2023/08/21 13:10:49 by dsilva-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

AR = ar
ARFLAGS = crs

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES = libft.h

SRC_PART1 = \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_bzero.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c

SRC_PART2 = \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

SRC_BONUS = \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRC_GNL = \
		  get_next_line.c \
		  get_next_line_utils.c \

SRC_PRINTF = 	\
		ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_nbr.c \
		ft_print_ptr.c \
		ft_print_unbr.c \
		ft_print_hex.c

SRCS = \
	$(SRC_PART1) \
	$(SRC_PART2) \
	$(SRC_BONUS) \
	$(SRC_GNL) \
	$(SRC_PRINTF)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@echo "$(BLUE)"
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(MAGENTA)Files and $(NAME)$(GREEN) compiled!$(WHITE)"

all: $(NAME)

%.o: %.c $(INCLUDES) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)
	@echo "$(MAGENTA)Removing files... $(GREEN)done!$(WHITE)"

fclean: clean
	$(RM) $(RMFLAG) $(NAME)
	@echo "$(MAGENTA)Removing $(NAME) $(GREEN)done!$(WHITE)"

re: fclean all

.PHONY: all clean fclean re

# Colors
GREEN = \033[92m
BLUE = \033[94m
MAGENTA = \033[95m
WHITE = \033[97m
