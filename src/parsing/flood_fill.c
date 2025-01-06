/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 08:20:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/06 09:26:45 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool		flood_fill(char **map, int x, int y, t_data *data);

int	flood_fill_map_and_island(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	map = map_duplicate(data->parsing.map);
	if (!map)
		return (ERROR);
	replace_space_by_set(map, ' ');
	// print_tab(map);
	while(map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if (map[x][y] == '0' || is_pos_char(map[x][y]))
			{
				if (flood_fill(map, x, y, data))
				{
					print_tab(map);
					free_split(map);
					return (ERROR);
				}
			}
			y++;
		}
		x++;
	}
	print_tab(map);
	free_split(map);
	return (SUCCESS);
}

bool	flood_fill(char **map, int x, int y, t_data *data)
{
	int	res;

	res = 0;
	if (map[x][y] == '1' || map[x][y] == '*')
		return (0);
	init_pos_S_N(data, map, x, y);
	init_pos_E_W(data, map, x, y);
	// if (data->parsing.nb_pos > 1)
		// return (ft_putstr_fd("Error\nCUB3D : Too many starting positions\n", 2), 1);
	if (map[x][y] == '0' || is_pos_char(map[x][y]))
		map[x][y] = '*';
	if (map[x][y] == ' ' || map[x][y] == '\n' || map[x][y] == '\0')
		return(ft_putstr_fd("Error\nCUB3D : Map is not closed\n", 2), 1);
	res = flood_fill(map, x - 1, y, data);
	if (res)
		return (res);
	res = flood_fill(map, x + 1, y, data);
	if (res)
		return (res);
	res = flood_fill(map, x, y - 1, data);
	if (res)
		return (res);
	res = flood_fill(map, x, y + 1, data);
	return (res);
}
