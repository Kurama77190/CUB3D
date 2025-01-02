/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_fd_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:54:25 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/01 13:14:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F' || c == 'C'
		|| c == '1' || c == '0' || c == '\n' || c == ' ' || c == '\0');
}

int	check_NO(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
		{
			j += 2;
			while (data->file[i][j] && ft_isspace(data->file[i][j]))
				j++;
			if (data->file[i][j] == '\0' || data->file[i][j] == '\n')
				return (ft_putstr_fd("Error\nCUB3D : NO path is missing\n", 2),
					ERROR);
			if (ft_strchr(data->file[i], '/') == NULL)
				return (ft_putstr_fd("Error\nCUB3D : NO path is missing\n", 2),
					ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (ft_putstr_fd("Error\nCUB3D : param NO not found.\n", 2), ERROR);
}

int	check_SO(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
		{
			j += 2;
			while (data->file[i][j] && ft_isspace(data->file[i][j]))
				j++;
			if (data->file[i][j] == '\0' || data->file[i][j] == '\n')
				return (ft_putstr_fd("Error\nSO path is missing", 2), ERROR);
			if (ft_strchr(data->file[i], '/') == NULL)
				return (ft_putstr_fd("Error\nSO path is missing", 2), ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (ft_putstr_fd("Error\nCUB3D : param SO not found.\n", 2), ERROR);
}

int	check_WE(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
		{
			j += 2;
			while (data->file[i][j] && ft_isspace(data->file[i][j]))
				j++;
			if (data->file[i][j] == '\0' || data->file[i][j] == '\n')
				return (ft_putstr_fd("Error\nWE path is missing", 2), ERROR);
			if (ft_strchr(data->file[i], '/') == NULL)
				return (ft_putstr_fd("Error\nWE path is missing", 2), ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (ft_putstr_fd("Error\nCUB3D : param WE not found.\n", 2), ERROR);
}

int	check_EA(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
		{
			j += 2;
			while (data->file[i][j] && ft_isspace(data->file[i][j]))
				j++;
			if (data->file[i][j] == '\0' || data->file[i][j] == '\n')
				return (ft_putstr_fd("Error\nEA path is missing", 2), ERROR);
			if (ft_strchr(data->file[i], '/') == NULL)
				return (ft_putstr_fd("Error\nEA path is missing", 2), ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (ft_putstr_fd("Error\nCUB3D : param EA not found.\n", 2), ERROR);
}
