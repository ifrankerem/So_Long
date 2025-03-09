/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:56:53 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 04:45:10 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_player(char **cpy_map, int x, int y)
{
	if (cpy_map[y][x] == '1' || cpy_map[y][x] == 'X' || cpy_map[y][x] == 'E')
		return ;
	cpy_map[y][x] = 'X';
	fill_player(cpy_map, x + 1, y);
	fill_player(cpy_map, x - 1, y);
	fill_player(cpy_map, x, y + 1);
	fill_player(cpy_map, x, y - 1);
}
void	fill_exit(char **cpy_map, int x, int y)
{
	if (cpy_map[y][x] == '1' || cpy_map[y][x] == 'X')
		return ;
	cpy_map[y][x] = 'X';
	fill_exit(cpy_map, x + 1, y);
	fill_exit(cpy_map, x - 1, y);
	fill_exit(cpy_map, x, y + 1);
	fill_exit(cpy_map, x, y - 1);
}
void	flood_fill_player(char **cpy_map, t_map *map)
{
	fill_player(cpy_map, map->player_x, map->player_y);
}
void	flood_fill_for_exit(char **cpy_map2, t_map *map)
{
	fill_exit(cpy_map2, map->exit_x, map->exit_y);
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

t_map	*exit_info(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'E')
			{
				map->exit_x = x;
				map->exit_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
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
void	copy_mapcontrol_player(t_map *map, char **cpy_map)
{
	int	x;
	int	y;

	y = 0;
	flood_fill_player(cpy_map, map);
	while (cpy_map[y])
	{
		x = 0;
		while (cpy_map[y][x])
		{
			if (cpy_map[y][x] == 'C')
			{
				free_cpymap(cpy_map);
				ft_error(map, 7);
			}
			x++;
		}
		y++;
	}
}
void	copy_mapcontrol_exit(t_map *map, char **cpy_map2)
{
	int	x;
	int	y;

	y = 0;
	flood_fill_for_exit(cpy_map2, map);
	while (cpy_map2[y])
	{
		x = 0;
		while (cpy_map2[y][x])
		{
			if (cpy_map2[y][x] == 'C')
			{
				free_cpymap(cpy_map2);
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
	char **cpy_map2;
	map = player_info(map);
	map = exit_info(map);
	cpy_map = make_copy(map);
	copy_mapcontrol_player(map, cpy_map);
	free_cpymap(cpy_map);
	cpy_map2 = make_copy(map);
	copy_mapcontrol_exit(map, cpy_map2);
	free_cpymap(cpy_map2);
	return (map);
}