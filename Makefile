# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 07:06:55 by sben-tay          #+#    #+#              #
#    Updated: 2024/12/30 15:42:19 by sben-tay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



MAKEFLAGS += --no-print-directory

# Définitions de base

NAME = cub3D
MLX = ./minilibx-linux
LIBFT = ./external/LIBFT/
GNL = ./external/GNL/src/
DPRINTF = ./external/DPRINTF/
CC = cc
CFLAGS = -Wall -Wextra -Werror -lm -g3
CPPFLAGS = -I./include -I./external/LIBFT/ -I./external/GNL/include -I./external/DPRINTF -I/usr/include -I$(MLX) -Imlx_linux
LDFLAGS = -L$(LIBFT) -lft -L$(DPRINTF) -lftprintf -L$(MLX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lbsd
PARS  = src/parsing/
BUILD = builder/

#=================================================__SRC__OF__PROJECT__=============================================================================
SRC := src/main.c src/ft_free_all.c \
	$(addprefix $(GNL), get_next_line.c get_next_line_utils.c) \
	$(addprefix $(PARS), handle_parsing.c get_fd_in_tab.c get_value_fd.c)

SRC_TEST = test/main.c

$(shell mkdir -p $(BUILD))

OBJ := $(SRC:%.c=$(BUILD)%.o)

OBJ_TEST := $(SRC_TEST:%.c=$(BUILD)%.o)
#OBJ_BNS = $(SRC_BNS:%.c=$(BUILD)%.o)
#==================================================================================================================================================

HEADER = ./include/cub3d.h
DEP := $(OBJ:.o=.d)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CYAN = \033[0;36m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
BLANC = \033[0;37m

all:	$(NAME)

$(NAME): $(OBJ)


#==================================ASCII_MOD_COMPILATION==================================

	@echo "$(GREEN)"

	@echo -n "Compilation progress: ["
	@for i in $$(seq 0.1 50); do \
		sleep 0.02; \
		echo -n "#"; \
	done
	@echo "] 100 %"
	@echo "Starting external projects $(MAGENTA)LIBFT$(CYAN), $(MAGENTA)DPRINTF$(CYAN), $(MAGENTA)MLX$(CYAN) and $(MAGENTA)GNL$(CYAN) compilations..."
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT) bonus
	@$(MAKE) $(MAKEFLAGS) -C $(MLX)
	@$(MAKE) $(MAKEFLAGS) -C $(DPRINTF)
	@echo "$(CYAN)Starting $(MAGENTA)CUB3D$(CYAN) compilations..."
	@sleep 1
	@$(CC) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "Done !$(BLANC)"

#=============================================================================================

test: $(OBJ_TEST)
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT) bonus
	@$(CC) $(OBJ_TEST) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -L$(LIBFT) -lft -o $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD)%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -MMD -MP



 # Règle pour créer l'exécutable bonus

bonus:

clean: # Règles pour nettoyer les fichiers objets

	@echo "$(RED)Cleaning up...$(NC)"
	@printf "$(CYAN)configure$(NC) [$(GREEN)info$(NC)] : Execute make clean from Projet of cub3d.\n"
	@$(MAKE) $(MAKEFLAGS) -C $(LIBFT) clean
	@printf "$(CYAN)configure$(NC) [$(GREEN)info$(NC)] : Execute make clean from Projet of libft.\n"
	@$(MAKE) $(MAKEFLAGS) -C $(DPRINTF) clean
	@printf "$(CYAN)configure$(NC) [$(GREEN)info$(NC)] : Execute make clean from Projet of dprintf.\n"
	@rm -rf $(BUILD)

fclean: clean # Règles pour nettoyer les fichiers objets et l'exécutable

	@rm -f $(NAME)
	@rm -f $(LIBFT)libft.a
	@rm -f $(DPRINTF)libftprintf.a
#	@rm -f $(NAME_BNS)


re: fclean all # Règle pour recompiler

.PHONY: all clean fclean re bonus test

-include $(DEP)