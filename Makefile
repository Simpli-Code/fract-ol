# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 11:45:40 by chruhin           #+#    #+#              #
#    Updated: 2024/03/15 09:00:27 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX				=		minilibx-linux
	EVENT			=		src/event_linux.c
	MLX_LIB			=		$(MLX)/libmlx.a
	FLAGS			=		-lXext -lX11 ./$(MLX)/libmlx.a -I./$(MLX) -L./$(MLX) -lmlx
endif
ifeq ($(UNAME_S),Darwin)
	MLX				=		minilibx-mac
	EVENT			=		src/event_mac.c
	FLAGS			=		-framework OpenGL -framework AppKit -I./$(MLX) -L./$(MLX) -lmlx
endif

NAME				=		fractol

SRC_DIR				=		src
OBJ_DIR				=		obj
INC_DIR				=		inc

DIRS				=		julia mandelbrot utils main $(EVENT)
SRCS				=		$(foreach dir,$(DIRS),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))

OBJS				=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEP					=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRCS))

INCS				=		$(addprefix -I, $(INC_DIR))

CFLAGS				=		-Wall -Wextra -MMD -g3 -Werror

RM					=		rm -rf

all:						$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): 					$(OBJS)
							@make -C $(MLX)
							@$(CC) -o $@ $? $(MLX_LIB) $(CFLAGS) $(FLAGS)
							@printf "${GRN}"'Compiled successfuly'"${RST}\n"

clean:
							@$(RM) $(OBJ_DIR)
							@make clean -C $(MLX)
							@printf "${RED}Deleted Object files${RST}\n"

fclean:						clean
							@$(RM) $(NAME)
							@printf "${RED}and the Executable${RST}\n"

re:							fclean all

.PHONY:						all clean fclean re

-include $(DEP)

RED					=		\e[1;31m
GRN					=		\e[1;32m
RST					=		\e[0m
