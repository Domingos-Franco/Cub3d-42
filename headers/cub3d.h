/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:33 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/20 16:24:38 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

/* EXTERNAL LIBS*/
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/* IMPORTED LIBS*/
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

/* LOCAL HEADERS*/
# include "structures.h"
# include "functions.h"

/* INTERATIVE KEYS DEFINITION*/
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

/* DEFINITION OF REPRESENTATIVE VALUES*/
# define HEIGTH 800
# define WIDTH 600
# define PIXEL 32
# define SET_ADDR 1
# define GET_ADDR 0
# define ERROR_MSG "error \n"
# define END_LINE "\n"
# define EMPTY NULL

#endif