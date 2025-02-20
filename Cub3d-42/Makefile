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

SRC = $(NAME).c gnl/get_next_line_utils.c gnl/get_next_line.c map_reading.c controls.c

OBJ = $(SRC:.c=.o)

CC =  cc
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Iminilibx-linux -Lminilibx-linux -Llibft -lft -lmlx -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)
$(OBJ):%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Iminilibx-linux -O3 -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

	

