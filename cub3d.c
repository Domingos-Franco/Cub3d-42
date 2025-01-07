/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:20:50 by dgermano          #+#    #+#             */
/*   Updated: 2025/01/07 13:14:31 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 int closeWindow(int key, void *arg)
 {
     (void)arg;
     if (key == ESC)
         exit(0);
     return (0);
 }

void print_square(t_cub *cub, int x, int y, int color)
{
    int size_x;
    int size_y;

    size_x = x;
    size_y = y;
    while(size_y < y + PIXEL - 4)
    {
        size_x = x;
        while(size_x <= x + PIXEL - 4)
        {
            mlx_pixel_put(cub->mlx, cub->window, size_x, size_y, color);
            size_x++;
        }
        size_y++;
    }
}

void load_map_2d(t_cub *cub)
{
    int i = 0;
    int j = 0;
    char **map = cub->map.map;
    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == '1')
                print_square(cub, j * PIXEL, i * PIXEL, cub->map.F_color);
            // else if(map[i][j] == '0')
            //     print_square(cub, j * PIXEL, i * PIXEL, cub->map.C_color);
            j++;
        }
        i++;
    }
    
    printf("player x %d y %d\n", cub->player.x, cub->player.y);
    print_square(cub, cub->player.x * PIXEL, cub->player.y * PIXEL, 0x00FF00);
}

int main(int ac, char **av)
{
    t_cub   cub;

    if(ac > 1)
    {
        cub.mlx = mlx_init();
        cub.window = mlx_new_window(cub.mlx, 1440 , 900, "Cub3d");
        init_player(&cub);
        mlx_key_hook(cub.window, closeWindow, NULL);
        map_reader(av[1], &cub.map);
        mlx_loop_hook(cub.mlx, control_loop, &cub);
        mlx_loop(cub.mlx);
    }
    return (0);
}


