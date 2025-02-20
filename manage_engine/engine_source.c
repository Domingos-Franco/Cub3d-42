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

int	initialize_graphics_resources(t_engine *graphics)
{
    
}