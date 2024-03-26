# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 14:28:56 by abentaye          #+#    #+#              #
#    Updated: 2024/03/26 15:24:15 by abentaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror
MLXPATH = ./mlx
MLXFLAGS := -Lmlx -lmlx -framework OpenGL -framework AppKit
RM := @rm -f
SRC := display_init.c \
		display.c \
		finishable.c \
		get_next_line.c \
		get_next_line_utils.c \
		hooks.c \
		main.c \
		moves.c \
		read_map.c \
		textures.c \
		utils.c \
		utils2.c \

GNL := get_next_line.c get_next_line_utils.c

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(NAME): $(SRC) $(MLXLIB)
	@echo $(Y)"Compiling $(NAME)..."$(X)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLXFLAGS)
	@echo $(G)"$(NAME) compiled successfully."$(X)

clean:
	@echo $(Y)"Cleaning $(NAME)..."$(X)
	@$(RM) $(NAME)
	@echo $(G)"$(NAME) cleaned."$(X)

fclean: clean
	@echo $(Y)"Cleaning all..."$(X)
	@$(RM)
	@echo $(G)"All cleaned."$(X)

re: fclean all


.PHONY: all clean fclean re norm
