/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:26:13 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 16:02:47 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_putnbr_fd(map->move_count, 0);
	map->move_count++;
	write(1, "\n", 1);
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y + my][map->player_x + mx] = 'P';
	map->player_x += mx;
	map->player_y += my;
	cast_image(map, 0, 0);
}
