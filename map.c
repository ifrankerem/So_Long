/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:13:23 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 01:33:58 by iarslan          ###   ########.fr       */
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

int	is_rectangle(const char *filename)
{
	char	*line;
	int		counter2;
	int		counter;
	int		fd;

	counter = 0;
	fd = open(filename, O_RDONLY, 0777);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line[counter] != '\n' && line[counter])
		counter++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		counter2 = 0;
		while (line[counter2] != '\n' && line[counter2])
			counter2++;
		if (counter != counter2)
			return (free(line), close(fd), 0);
	}
	return (free(line), close(fd), 1);
}

int	is_valid(const char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY, 0777);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (!((line[i] == '0') || (line[i] == '1') || (line[i] == 'C')
					|| (line[i] == 'E') || (line[i] == 'P')
					|| (line[i] == '\n')))
				return (free(line), close(fd), 0);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), 1);
}
int	wallcontrol(const char *filename)
{
	int		fd;
	char	*line;
	int		counter;
	int		len;
	char	*next_line;

	fd = open(filename, O_RDONLY, 0777);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	counter = 0;
	while (line[counter] != '\n' && line[counter])
	{
		if (!(line[counter] == '1'))
			return ((free(line), close(fd), 0));
		counter++;
	}
	next_line = get_next_line(fd);
	if (!next_line)
		return (free(line), close(fd), 0);
	while (next_line)
	{
		free(line);
		line = next_line; // önceki satır
		len = ft_strlen(line);
		next_line = get_next_line(fd);
		if (!next_line)
			// eğer son satır burda null gelirse yukardaki line = next_line önceki satırı ifade etmis oluyor. o yüzdne son satırı tutmus oluosun
			break ;
		if (!((line[0] == '1') && (line[len - 2] == '1')))
			return (free(line), free(next_line), close(fd), 0);
	}
	counter = 0;
	while (line[counter])
	{
		if (!(line[counter] == '1' || line[len - 1] == '\n'))
			return (free(line), close(fd), 0);
		counter++;
	}
	return ((free(line), free(next_line), close(fd), 1));
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", file_name_control(av[1]));
		printf("%d\n", is_rectangle(av[1]));
		printf("%d\n", is_valid(av[1]));
		printf("%d\n", wallcontrol(av[1]));
	}
}

static void	fload_fill(int y, int x, char **map) // bu fonksiyon exit ve
{
	char c;

	c = map[y][x];
	if (c == '1')
		return ;
	map[y][x] = '1';
	if (c == 'E')
		return ;
	fload_fill(y + 1, x, map);
	fload_fill(y - 1, x, map);
	fload_fill(y, x + 1, map);
	fload_fill(y, x - 1, map);
}