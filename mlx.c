/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:26:48 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 16:34:47 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*open_window(t_map *map)
{
	int	i;

	i = 64;
	map->mlx_ptr = mlx_init();
	if (!(map->mlx_ptr))
		ft_error(map, 8);
	map->win = mlx_new_window(map->mlx_ptr, map->column_number * i,
			map->line_number * i, "./so_long");
	if (!map->win)
		return (mlx_destroy_display(map->mlx_ptr), free(map->mlx_ptr),
			ft_error(map, 8), NULL);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/wall.xpm", &i,
			&i);
	map->coin = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/coin.xpm", &i,
			&i);
	map->exit = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/exit.xpm", &i,
			&i);
	map->background = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/background.xpm", &i, &i);
	map->player = mlx_xpm_file_to_image(map->mlx_ptr, "./textures/player.xpm",
			&i, &i);
	map = cast_image(map, 0, 0);
	return (map);
}

t_map	*cast_image(t_map *map, int x, int y)
{
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			mlx_put_image_to_window(map->mlx_ptr, map->win, map->background, x
				* 64, y * 64);
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win, map->wall, x
					* 64, y * 64);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win, map->coin, x
					* 64, y * 64);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win, map->player, x
					* 64, y * 64);
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win, map->exit, x
					* 64, y * 64);
			x++;
		}
		y++;
	}
	return (map);
}

int	close_window(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->player);
	mlx_destroy_image(map->mlx_ptr, map->coin);
	mlx_destroy_image(map->mlx_ptr, map->background);
	mlx_destroy_image(map->mlx_ptr, map->exit);
	mlx_destroy_image(map->mlx_ptr, map->wall);
	mlx_destroy_window(map->mlx_ptr, map->win);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	map_free(map);
	exit(0);
	return (0);
}
