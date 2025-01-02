/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_fd_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:12:03 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/01 15:10:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_F(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (data->file[i][j] == 'F' && data->file[i][j + 1] == ' ')
		{
			j += 2;
			while (data->file[i][j] && ft_isspace(data->file[i][j]))
				j++;
			if (data->file[i][j] == '\0' || data->file[i][j] == '\n')
				return (ft_putstr_fd("Error\nCUB3D: param F color is missing\n", \
						2), ERROR);
			if (check_format_rgb(data->file[i] + j) == ERROR)
				return (ft_putstr_fd("Error\nCUB3D: param F need RGB format\n", \
						2), ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (ft_putstr_fd("Error\nCUB3D : param F not found.\n", 2), ERROR);
}

int	check_C(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (data->file[i][j] == 'C' && data->file[i][j + 1] == ' ')
		{
			j += 2;
			while (data->file[i][j] && ft_isspace(data->file[i][j]))
				j++;
			if (data->file[i][j] == '\0' || data->file[i][j] == '\n')
				return (ft_putstr_fd("Error\nCUB3D: param C color is missing\n", \
						2), ERROR);
			if (check_format_rgb(data->file[i] + j) == ERROR)
				return (ft_putstr_fd("Error\nCUB3D: param C need RGB format\n", \
						2), ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (ft_putstr_fd("Error\nCUB3D : param C not found.\n", 2), ERROR);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->file[i])
		i++;
	i--;
	while (data->file[i][0] == '\n')
		i--;
	while (ft_isspace(data->file[i][j]))
		j++;
	if (data->file[i][j] == '1' || data->file[i][j] == '0')
		return (SUCCESS);
	return (ft_putstr_fd("Error\nCUB3D : Map is missing or not last param\n", \
			2), ERROR);
}

int	check_format_rgb(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ',' && !ft_isspace(str[i]))
		{
			if (!ft_isdigit(str[i]))
				return (ERROR);
		}
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (ERROR);
	return (SUCCESS);
}

int	check_invalid_param(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (!valid_char(data->file[i][j]))
			return (ft_putstr_fd("Error\nCUB3D : Invalid param in file\n", 2), \
				ERROR);
		i++;
	}
	return (SUCCESS);
}