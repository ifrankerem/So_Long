/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:34:03 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 01:34:04 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*info(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y])
		y++;
	while (map->map[0][x])
		x++;
	map->line_number = y;
	map->column_number = x;
	return (map);
}

void	is_rectangle(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < map->line_number)
	{
		x = 0;
		while (map->map[y][x])
			x++;
		if (x != map->column_number)
			ft_error(map, 0);
		y++;
	}
}

void	wallcontrol(t_map *map, int x, int y)
{
	if (map->line_number < 3)
		ft_error(map, 1);
	while ((map->map[0][x] != '\n') && (map->map[0][x]))
	{
		if (!(map->map[0][x] == '1'))
			ft_error(map, 2);
		x++;
	}
	while (y < ((map->line_number) - 1))
	{
		x = 0;
		if (!((map->map[y][0] == '1') && (map->map[y][(map->column_number)
					- 1] == '1')))
			ft_error(map, 2);
		y++;
	}
	x = 0;
	while (map->map[map->line_number - 1][x])
	{
		if (map->map[map->line_number - 1][x] != '1')
			ft_error(map, 2);
		x++;
	}
}

void	is_valid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->line_number)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (!((map->map[y][x] == '1') || (map->map[y][x] == '0')
					|| (map->map[y][x] == 'E') || (map->map[y][x] == 'P')
					|| (map->map[y][x] == 'C')))
				ft_error(map, 3);
			x++;
		}
		y++;
	}
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

void	ft_error(t_map *map, int error_code)
{
	map_free(map);
	write(1, "Error\n", 6);
	if (error_code == 0)
		write(1, "Map is not rectangle!!\n", 23);
	else if (error_code == 1)
		write(1, "Not enough line for the map!!\n", 30);
	else if (error_code == 2)
		write(1, "Map is not surrounded wall!!\n", 29);
	else if (error_code == 3)
		write(1, "Invalid Argument !!\n", 20);
	else if (error_code == 4)
		write(1, "Invalid Argument Count!!\n", 25);
	else if (error_code == 5)
		write(1, "Map is not reachable!!\n", 23);
	else if (error_code == 6)
		write(1, "Empty Line in the map!!\n", 24);
	else if (error_code == 7)
		write(1, "Invalid Coin or Exit Replacement!!\n", 35);
	else if (error_code == 8)
		write(1, "Malloc Error\n", 13);
	else if (error_code == 9)
		write(1, "Invalid Map Name\n", 17);
	exit(1);
}
void	map_free(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->map == NULL)
	{
		free(map);
		return ;
	}
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
t_map	*control(t_map *map)
{
	map = info(map);
	is_rectangle(map);
	is_valid(map);
	wallcontrol(map, 0, 1);
	map = map_elements(map);
	return (map);
}