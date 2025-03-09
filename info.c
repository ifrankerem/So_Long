/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:30:08 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 15:35:48 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*info(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (map == NULL || map->map == NULL)
		ft_error(map, 6);
	while (map->map[y])
		y++;
	while (map->map[0][x])
		x++;
	map->line_number = y;
	map->column_number = x;
	return (map);
}

t_map	*map_elements(t_map *map)
{
	int	y;
	int	x;

	map->c = 0;
	map->e = 0;
	map->p = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
				(map->c)++;
			if (map->map[y][x] == 'E')
				(map->e)++;
			if (map->map[y][x] == 'P')
				(map->p)++;
			x++;
		}
		y++;
	}
	if (!(map->p == 1 && map->c >= 1 && map->e == 1))
		ft_error(map, 4);
	return (map);
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
