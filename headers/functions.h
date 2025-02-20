/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:12:50 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/20 15:41:25 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/*ENGINE_SOURCE FUNCTIONS*/
t_engine	*address_of_engine(const int operation);
int			initialize_graphics_resources(t_engine *graphics);

int			control_loop(t_cub *cub);
int			closeWindow(int key, void *arg);
int			map_reader(char *path, t_map *map);
void		init_player(t_cub *cub);
void		load_map_2d(t_cub *cub);
void		print_square(t_cub *cub, int x, int y, int color);

#endif