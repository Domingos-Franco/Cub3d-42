/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:33 by dgermano          #+#    #+#             */
/*   Updated: 2025/01/07 13:01:18 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define PIXEL 32

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

int					control_loop(t_cub *cub);
int					closeWindow(int key, void *arg);
int					map_reader(char *path, t_map *map);
void				init_player(t_cub *cub);
void				load_map_2d(t_cub *cub);
void				print_square(t_cub *cub, int x, int y, int color);
#endif