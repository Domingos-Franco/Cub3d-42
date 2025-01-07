/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:54:58 by dgermano          #+#    #+#             */
/*   Updated: 2025/01/07 12:33:33 by dgermano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int mat_len(char **mat)
{
	int i= -1;
	while(mat[++i])
		;
	return (i);
}

int	verify_extension_file(char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (*extension != '.')
		return (1);
	extension++;
	if (ft_strncmp(extension, "xpm", 3) != 0)
		return (1);
	return (0);
}

int	check_path(char *line, char *locate, t_map *map)
{
	char	**arguments;

	arguments = ft_split(line, ' ');
	if (mat_len(arguments) != 2)
		return (1);
	if (ft_strncmp((*arguments), locate, 2) != 0)
		return (1);
	if (verify_extension_file(arguments[1]))
		return (1);
	if (ft_strncmp(locate, "NO", 2) == 0)
		map->NO = ft_strdup(arguments[1]);
	else if (ft_strncmp(locate, "SO", 2) == 0)
		map->SO = ft_strdup(arguments[1]);
	else if (ft_strncmp(locate, "WE", 2) == 0)
		map->WE = ft_strdup(arguments[1]);
	else if (ft_strncmp(locate, "EA", 2) == 0)
		map->EA = ft_strdup(arguments[1]);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void	search_and_replace(char *string, char search, char replace)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == search)
			string[i] = replace;
		i++;
	}
}

void free_mat(char **mat)
{
    int i = -1;
    
	if(!mat || !(*mat))
		return;
    while (mat[++i])
        free(mat[i]);
    free(mat);
}

int	get_colors(char *line, t_map *map)
{
	char	**arguments;
	int		value;

	search_and_replace(line, ' ', ',');
	arguments = ft_split(line, ',');
	if (mat_len(arguments) != 4)
    {
		return (1);
        free_mat(arguments);
    }
	value = create_trgb(0, ft_atoi(arguments[1]), ft_atoi(arguments[2]),
			ft_atoi(arguments[3]));
	if (arguments[0][0] == 'F')
		map->F_color = value;
	else if (arguments[0][0] == 'C')
		map->C_color = value;
    else
    {
        free_mat(arguments);
        return (1);
    }
    return (0);
}
char **mat_dup(char **mat)
{
	char **new_mat;
	int i = -1;
	new_mat = (char **)malloc(sizeof(char *) * mat_len(mat));
	while(mat[++i])
		new_mat[i] = ft_strdup(mat[i]);
	new_mat[i] = NULL;
	return (new_mat);
}
void mat_copy(char **dst, char **src)
{
	int i = -1;
	while(src[++i])
		dst[i] = ft_strdup(src[i]);
}

int get_map(int fd, t_map *map_struct)
{
    char **map_tmp;
    char **map;
    char *line;
    int last_pos = 0;

    map_tmp = (char **)malloc(sizeof(char *) * 2);
    map_tmp[0] = get_next_line(fd);
    map_tmp[1] = NULL;
    while (1)
    {
        line = get_next_line(fd);
        last_pos = mat_len(map_tmp);
        map = (char **)malloc(sizeof(char *) * (last_pos + 2));
		mat_copy(map, map_tmp);
		map[last_pos] = line;
		map[last_pos + 1] = NULL;
		free_mat(map_tmp);
        map_tmp = map;
        if (!line)
            break;
    }
	map_struct->map = mat_dup(map);
    free_mat(map);
    return (0);
}


int is_empty(char *line)
{
	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	if(*line == '\0')
		return (1);
	return (0);
}
int	map_reader(char *path, t_map *map)
{
	char *cardial_mat[5] = {"NO", "SO", "WE", "EA", NULL};
    char *colors_mat[3] = {"F", "C", NULL};
	char *line;
	int fd = open(path, O_RDONLY);
	int i = 0;
	while (cardial_mat[i])
	{
		line = get_next_line(fd);
		
		printf("Line Readed >> %s", line);
		if(!is_empty(line))
		{
			if (check_path(line, cardial_mat[i], map))
			{
				free(line);
				printf("here\n");
				return (1);
			}
			else
				i++;
		}
		free(line);
	}
    i = 0;
    while (colors_mat[i])
    {
        line = get_next_line(fd);
		if(!is_empty(line))
		{
			if (get_colors(line, map))
			{
				free(line);
				return (1);
			}
		}
		else
			i++;
		free(line);
    }
	printf("F-color :%X\n", map->F_color);
	printf("C-color :%X\n", map->C_color);
	if(get_map(fd, map))
		return (1);
	i = -1;
	while (map->map[++i])
		printf("%s", map->map[i]);
	return (0);
}
