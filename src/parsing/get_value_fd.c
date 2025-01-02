/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:54:39 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/01 16:13:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgb(t_data *data, char *line);
static int	get_path_wall(t_data *data, char *line);

int	get_value_fd(t_data *data)
{
	int	i;

	i = 0;
	while (data->file[i])
	{
		get_path_wall(data, data->file[i]);
		get_rgb(data, data->file[i]);
		i++;
	}
	i = 0;
	return (SUCCESS);
}

static int	get_path_wall(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		data->parsing.no = ft_strtrim(line + 2, " ");
		return (SUCCESS);
	}
	else if (line[i] == 'S' && line[i + 1] == 'O')
	{
		data->parsing.so = ft_strtrim(line + 2, " ");
		return (SUCCESS);
	}
	else if (line[i] == 'W' && line[i + 1] == 'E')
	{
		data->parsing.we = ft_strtrim(line + 2, " ");
		return (SUCCESS);
	}
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (data->parsing.ea = ft_strtrim(line + 2, " "), (SUCCESS));
	return (SUCCESS);
}

static int	get_rgb(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		data->parsing.f = ft_strtrim(line + 1, " ");
		return (SUCCESS);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		data->parsing.c = ft_strtrim(line + 1, " ");
		return (SUCCESS);
	}
	return (SUCCESS);
}
