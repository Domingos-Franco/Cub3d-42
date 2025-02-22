/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:31:46 by dgermano          #+#    #+#             */
/*   Updated: 2025/02/20 15:41:31 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
int cross_button(void *addr)
{
	(void)addr;
	exit(0);
	return (0);
}
int	main(void)
{
	t_engine *engine;

	engine = (t_engine *)malloc(sizeof(t_engine));
	if(initialize_graphics_resources(engine))
		return (1);
	mlx_hook(engine->graphics->x_conection, 17, 1L << 5, cross_button, NULL);
	mlx_loop(engine->graphics->x_conection);
	return (0);
}