/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:54:39 by sben-tay          #+#    #+#             */
/*   Updated: 2024/12/30 15:28:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_rgb(t_data *data, char *line);
static int	check_path_wall(t_data *data, char *line);

int	init_data_fd(t_data *data)
{
	int	i;

	i = 0;
	while (data->file[i])
	{
		check_path_wall(data, data->file[i]);
		check_rgb(data, data->file[i]);
		i++;
	}
	i = 0;
	return (SUCCESS);
}

static int	check_path_wall(t_data *data, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		data->parsing.no = ft_strtrim(line + 2, " ");
		return (SUCCESS);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		data->parsing.so = ft_strtrim(line + 2, " ");
		return (SUCCESS);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		data->parsing.we = ft_strtrim(line + 2, " ");
		return (SUCCESS);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		data->parsing.ea = ft_strtrim(line + 2, " ");
		return (SUCCESS);
	}
	return (SUCCESS);
}

static int	check_rgb(t_data *data, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		data->parsing.f = ft_strtrim(line + 1, " ");
		return (SUCCESS);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		data->parsing.c = ft_strtrim(line + 1, " ");
		return (SUCCESS);
	}
	return (SUCCESS);
}
