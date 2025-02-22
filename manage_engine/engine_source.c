/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_source.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:05:58 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/20 15:41:30 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_engine	*address_of_engine(const int operation)
{
	static t_engine	*engine_addr;

	if (operation == SET_ADDR)
	{
		engine_addr = (t_engine *)malloc(sizeof(t_engine));
		return (engine_addr);
	}
	else if (operation == GET_ADDR)
		if (engine_addr)
			return (engine_addr);
	return (NULL);
}

int	initialize_graphics_resources(t_engine *engine)
{
	t_graphic *graphics;
	int temp;
	char *tmp;

	engine->graphics = (t_graphic *)malloc(sizeof(t_graphic));
	graphics = engine->graphics;
	graphics->x_conection = mlx_init();
	if (!graphics->x_conection)
		return (1);
	graphics->x_screen = mlx_new_window(graphics->x_conection, WIDTH, HEIGTH, "Cub3D");
	if (!graphics->x_screen)
		return (1);
	graphics->xs_scene = mlx_new_image(graphics->x_conection, WIDTH, HEIGTH);
	if (!graphics->xs_scene)
		return (1);
	tmp = mlx_get_data_addr(graphics->xs_scene, &temp, &temp, &temp);
	if (!tmp)
		return (1);
	else
		graphics->xs_scene_data = (int *)tmp;
    return (0);
}