/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 06:42:27 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/06 13:28:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_size_map(t_data *data);

int	check_valid_map(t_data *data)
{
	if (check_space_in_map(data) == ERROR)
		return (ERROR);
	if (check_valid_map_char(data) == ERROR)
		return (ERROR);
	if (check_first_last_line(data) == ERROR)
		return (ERROR);
	if (flood_fill_map_and_island(data) == ERROR)
		return (ERROR);
	// replace_space_by_set(data->parsing.map, '0');
	if (get_size_map(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	get_size_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->parsing.map[i])
	{
		j = 0;
		while (data->parsing.map[i][j])
			j++;
		i++;
	}
	data->parsing.height_maps = i * 64;
	data->parsing.lenth_maps = j * 64;
	if (!data->parsing.height_maps || !data->parsing.lenth_maps)
	{
		ft_putendl_fd("Error\nMap is empty.", 2);
		return (ERROR);
	}
	return (SUCCESS);
}
