/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:07:26 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 16:36:22 by iarslan          ###   ########.fr       */
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
		whole = ft_combining(fd, line, whole, map);
	}
	map->map = ft_split(whole, '\n');
	free(whole);
	return (map);
}

char	*ft_combining(int fd, char *line, char *whole, t_map *map)
{
	char	*temp;

	empty_line_case(fd, line, whole, map);
	temp = whole;
	whole = ft_strjoin(whole, line);
	if (!whole)
		ft_error(map, 8);
	free(temp);
	free(line);
	return (whole);
}

void	empty_line_case(int fd, char *line, char *whole, t_map *map)
{
	if (line[0] == '\n')
	{
		free(line);
		free(whole);
		while (line)
		{
			line = get_next_line(fd);
			free(line);
		}
		close(fd);
		ft_error(map, 6);
	}
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
		mlx_hook(map->win, 17, 0, close_window, map);
		mlx_loop(map->mlx_ptr);
	}
	else
	{
		write(1, "Error\n", 6);
		write(1, "Invalid Map Name\n", 17);
	}
}
