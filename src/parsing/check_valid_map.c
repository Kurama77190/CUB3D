/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 06:42:27 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/05 15:18:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid_map(t_data *data)
{
	if (check_valid_map_char(data) == ERROR)
		return (ERROR);
	if (flood_fill_map_and_island(data) == ERROR)
		return (ERROR);
	// copy the map in a var tmp
	// check if the map is closed with flood fill
	// if not return error
	return (SUCCESS);
}
