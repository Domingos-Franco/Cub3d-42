/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:08:40 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/20 15:41:22 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct s_graphic
{
	void *x_conection;
	void *x_screen;
	void *xs_scene;
	int *xs_scene_data;
} t_graphic;

typedef struct s_cub
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	int F_color;
	int C_color;
	char **map;
} t_cub;

typedef struct s_cubg
{
	int x;
	int y;
	bool left;
	bool right;
	bool forward;
	bool back;
} t_cubg;

typedef struct s_engine
{
	t_cub	resource_data;
	t_cubg	game;
	t_graphic *graphics;
} t_engine;

#endif