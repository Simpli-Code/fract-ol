# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 11:45:40 by chruhin           #+#    #+#              #
#    Updated: 2024/03/11 08:01:40 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME				=		fractol

# Directories
SRC_DIR				=		src
OBJ_DIR				=		obj
INC_DIR				=		inc

# Source files
DIRS				=		julia mandelbrot utils main
SRCS				=		$(foreach dir,$(DIRS),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))

# Object files
OBJS				=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEP					=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRCS))

# Header files
INCS				=		$(addprefix -I, $(INC_DIR))

# mlx library
MLX_LNK				=		-l mlx -lXext -lX11

# Compiler flags
CFLAGS				=		-Wall -Wextra -MMD -g3 -Werror

# Cleanup
RM					=		rm -rf

# Targets
all:						$(OBJ_DIR) $(NAME)

# Create a Dir for obj
$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)
# Compiling obj
$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Compiling exec
$(NAME): 					$(OBJS)
							@$(CC) $(CFLAGS) $(MLX_LNK) -o $(NAME) $(OBJS) -lm
							@printf "${GRN}"'Compiled successfuly'"${RST}\n"

# Remove object files
clean:
							@$(RM) $(OBJ_DIR)
							@printf "${RED}Deleted Object files${RST}\n"

# Remove obj & exec files
fclean:						clean
							@$(RM) $(NAME)
							@printf "${RED}and the Executable${RST}\n"

# remove all & recompile
re:							fclean all

# No exceptions
.PHONY:						all clean fclean re

# to include the dependency files
-include $(DEP)

# color codes
RED					=		\e[1;31m
GRN					=		\e[1;32m
RST					=		\e[0m

#	USEFUL RESOURCES
#	https://theses.liacs.nl/pdf/2018-2019-JonckheereLSde.pdf
#	https://acko.net/blog/how-to-fold-a-julia-fractal/
#	https://harm-smits.github.io/42docs/
#	https://en.wikipedia.org/wiki/Julia_set
#	https://rgbacolorpicker.com/
