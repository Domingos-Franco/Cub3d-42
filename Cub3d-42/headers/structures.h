/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:08:40 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/19 09:38:57 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef STRUCTURES_H
# define STRUCTURES_H



typedef struct s_graphic
{
   void *x_conection;
   void *x_screen;
   void *x_screen_data;
} t_graphic;

typedef struct s_engine
{
    t_memory        *memory;
	t_graphic		*graphics;
}					t_engine;

typedef struct s_map
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	int				F_color;
	int				C_color;
	char			**map;
}					t_map;

typedef struct s_cub_player
{
	int				x;
	int				y;
	bool			left;
	bool			right;
	bool			forward;
	bool			back;
}					t_cub_player;

typedef struct s_cub
{
	void			*mlx;
	void			*window;
	t_cub_player	player;
	t_map			map;
}					t_cub;

#endif