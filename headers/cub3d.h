/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:33 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/20 15:41:26 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

/* EXTERNAL LIBS*/
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* IMPORTED LIBS*/
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

/* LOCAL HEADERS*/
#include "structures.h"
#include "functions.h"

/* INTERATIVE KEYS DEFINITION*/
#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363

/* DEFINITION OF REPRESENTATIVE VALUES*/
#define PIXEL 32
#define SET_ADDR 1
#define GET_ADDR 0
#define WIDTH 800
#define HEIGTH 600

#endif