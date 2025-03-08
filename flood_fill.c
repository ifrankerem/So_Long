/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:56:53 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 01:31:41 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **cpy_map, int x, int y)
{
	if (cpy_map[y][x] == '1')
		return ;
	if (cpy_map[y][x] == 'E')
		return ;
	cpy_map[y][x] = '1';
	fill(cpy_map, x + 1, y);
	fill(cpy_map, x - 1, y);
	fill(cpy_map, x, y + 1);
	fill(cpy_map, x, y - 1);
}
void	flood_fill(char **cpy_map, t_map *map)
{
	cpy_map[map->player_y][map->player_x] = '0';
	fill(cpy_map, map->player_x, map->player_y);
}
t_map	*player_info(t_map *map)
{
	int	px;
	int	py;

	py = 0;
	while (map->map[py])
	{
		px = 0;
		while (map->map[py][px])
		{
			if (map->map[py][px] == 'P')
			{
				map->player_x = px;
				map->player_y = py;
				break ;
			}
			px++;
		}
		py++;
	}
	map->move_count = 1;
	return (map);
}

char	**make_copy(t_map *map)
{
	char	**cpy_map;
	int		x;
	int		y;

	y = 0;
	cpy_map = (char **)malloc(sizeof(char *) * (map->line_number + 1));
	if (!cpy_map)
		ft_error(map, 8);
	while (map->map[y])
	{
		x = 0;
		cpy_map[y] = (char *)malloc(sizeof(char) * (map->column_number) + 1);
		if (!(cpy_map[y]))
			ft_error(map, 8);
		while (map->map[y][x])
		{
			cpy_map[y][x] = map->map[y][x];
			x++;
		}
		cpy_map[y][x] = '\0';
		y++;
	}
	cpy_map[y] = '\0';
	return (cpy_map);
}
void	copy_mapcontrol(t_map *map, char **cpy_map)
{
	int	x;
	int	y;

	y = 0;
	while (cpy_map[y])
	{
		x = 0;
		while (cpy_map[y][x])
		{
			if (cpy_map[y][x] != '1')
			{
				free_cpymap(cpy_map);
				ft_error(map, 7);
			}
			x++;
		}
		y++;
	}
}

void	free_cpymap(char **cpy_map)
{
	int	i;

	i = 0;
	if (!cpy_map)
		return ;
	while (cpy_map[i])
	{
		free(cpy_map[i]);
		i++;
	}
	free(cpy_map);
}

t_map	*mapcontrol2(t_map *map)
{
	char **cpy_map;
	map = player_info(map);
	cpy_map = make_copy(map);
	flood_fill(cpy_map, map);
	copy_mapcontrol(map, cpy_map);
	free_cpymap(cpy_map);
	return (map);
}