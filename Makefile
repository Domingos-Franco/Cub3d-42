# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgermano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 10:28:43 by dgermano          #+#    #+#              #
#    Updated: 2025/01/07 11:02:09 by dgermano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
COMPILER = cc
CLEANER = rm -rf
FLAGS = -Wall -Wextra -Werror

# Diretórios e arquivos
GNL_FILES = get_next_line_utils.c get_next_line.c  
GNL = $(addprefix gnl/, $(GNL_FILES))
MANAGE_ENGINE_FILES = engine_source.c raycast.c
MANAGE_ENGINE = $(addprefix manage_engine/, $(MANAGE_ENGINE_FILES))

SRC = $(GNL) $(MANAGE_ENGINE)
OBJ = $(SRC:%.c=%.o)

# Bibliotecas e includes
LIBS = -Lminilibx-linux -Llibft -lft -lmlx -lmlx_Linux -lXext -lX11 -lm -lz 
INCLUDES = -Iminilibx-linux -Iheaders -Ignl -Ilibft

# Regras principais
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx-linux
	$(COMPILER) -g $(FLAGS) $(OBJ) $(LIBS) $(INCLUDES) -o $(NAME)

# Regra para criar os objetos
%.o: %.c
	$(COMPILER) -g $(FLAGS) $(INCLUDES) -c $< -o $@

# Limpeza
clean:
	make fclean -C libft
	make clean -C minilibx-linux
	$(CLEANER) $(OBJ)

fclean: clean
	$(CLEANER) $(NAME)

re: fclean all

.PHONY: all clean fclean re