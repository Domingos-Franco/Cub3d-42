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

int KeyPress(int key, t_cub *cub)
{
   if(key == W)
        cub->player.forward = true;
    if(key == S)
        cub->player.back = true;
    if(key == A)
        cub->player.left = true;
    if(key == D)
        cub->player.right = true;
    return (0);
}

int KeyUnPress(int key, t_cub *cub)
{
    if(key == ESC)
        exit(0);
    if(key == W)
        cub->player.forward = false;
    if(key == S)
        cub->player.back = false;
    if(key == A)
        cub->player.left = false;
    if(key == D)
        cub->player.right = false;
    printf("key %d\n", key);
    return (0);
}

void init_player(t_cub *cub)
{
    cub->player.x = 5;
    cub->player.y = 5;
    cub->player.left = false;
    cub->player.right = false;
    cub->player.forward = false;
    cub->player.back = false;
}
void move_player(t_cub_player *player)
{
    if(player->forward)
        player->y++;
    if(player->back)
        player->y--;
    if(player->left)
        player->x--;
    if(player->right)
        player->x++;
}

void show_player(t_cub *cub)
{
    print_square(cub, cub->player.x * PIXEL, cub->player.y * PIXEL, 0x00FF00);
}

int control_loop(t_cub *cub)
{
    printf("loop on\n");
    mlx_hook(cub->window, 2, 1L<<0, KeyPress, cub);
    move_player(&cub->player);
    load_map_2d(cub);
    //show_player(cub);
    //mlx_hook(cub->window, 3, 1L<<1, KeyUnPress, cub);
    //mlx_hook(cub->window, 17, 1L<<17, closeWindow, cub);
    return (0);
}