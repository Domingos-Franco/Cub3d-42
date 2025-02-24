/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:31:46 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/24 15:58:57 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_engine *engine;

	engine = address_of_engine(SET_ADDR);
	engine->graphics->x_conection = mlx_init();
	if (engine->graphics->x_conection == EMPTY)
	{
        ft_perror("Conection with X-window fail", EMPTY, EMPTY);
		return (1);
	}
	else
	{
		engine->graphics->x_screen = mlx_new_window(engine->graphics->x_conection, WIDTH, HEIGTH, "CUB3D");
		if (engine->graphics->x_screen == EMPTY)
		{
			ft_perror("Conection with X-window fail", EMPTY, EMPTY);
			return (1);
		}
	}
	

	return (0);
}