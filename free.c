/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:28:08 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/09 15:31:10 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
