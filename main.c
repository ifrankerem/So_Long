/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:07:26 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 05:06:37 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_name_control(char *av)
{
	int	len;

	len = 0;
	len = ft_strlen(av);
	if (len < 4)
		return (0);
	if (av[len - 4] == '.' && av[len - 3] == 'b' && av[len - 2] == 'e' && av[len
		- 1] == 'r')
		return (1);
	return (0);
}

t_map	*read_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	char	*whole;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(map, 9);
	whole = ft_strdup("");
	if (!whole)
		ft_error(map, 8);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			free(whole);
			while ((line = get_next_line(fd)))
				free(line);
			close(fd);
			ft_error(map, 6);
		}
		temp = whole;
		whole = ft_strjoin(whole, line);
		if (!whole)
			ft_error(map, 8);
		free(temp);
		free(line);
	}
	map->map = ft_split(whole, '\n');
	free(whole);
	return (map);
}

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
	map = cast_image(map);
	return (map);
}
t_map	*cast_image(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
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

void	close_window(t_map *map)
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
}
int	movement_and_exit(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
	{
		write(1, "Quitting game by pressing ESC\n", 30);
		close_window(map);
	}
	if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
		player_move(map, -1, 0);
	if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
		player_move(map, 0, -1);
	if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
		player_move(map, 1, 0);
	if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
		player_move(map, 0, 1);
	return (0);
}

void	player_move(t_map *map, int my, int mx)
{
	if (map->map[map->player_y + my][map->player_x + mx] == '1')
		return ;
	else if (map->map[map->player_y + my][map->player_x + mx] == 'E'
		&& map->c == 0)
		close_window(map);
	else if (map->map[map->player_y + my][map->player_x + mx] == 'E')
		return ;
	if (map->map[map->player_y + my][map->player_x + mx] == 'C')
		(map->c)--;
	ft_putnbr(map->move_count);
	map->move_count++;
	write(1, "\n", 1);
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y + my][map->player_x + mx] = 'P';
	map->player_x += mx;
	map->player_y += my;
	cast_image(map);
}
int	main(int ac, char *av[])
{
	t_map	*map;

	if (ac == 2)
	{
		map = malloc(sizeof(t_map));
		if (!map)
			ft_error(map, 8);
		map->map = NULL;
		if (!(file_name_control(av[1])))
			ft_error(map, 9);
		map = read_map(map, av[1]);
		map = control(map);
		map = mapcontrol2(map);
		map = open_window(map);
		mlx_key_hook(map->win, movement_and_exit, map);
		mlx_loop(map->mlx_ptr);
	}
	else
	{
		write(1, "Error\n", 6);
		write(1, "Invalid Map Name\n", 17);
	}
}
