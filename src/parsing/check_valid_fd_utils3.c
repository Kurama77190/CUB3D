/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_fd_utils3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:12:25 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/04 05:31:57 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	update_dejavu(char **file, int i, int j, bool *dejavu);

bool	valid_char_map(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i + 1] && str[i] == 'E' && str[i + 1] == 'A')
			return (false);
		if (str[i + 1] && str[i] == 'W' && str[i + 1] == 'E')
			return (false);
		if (str[i + 1] && str[i] == 'S' && str[i + 1] == 'O')
			return (false);
		if (str[i + 1] && str[i] == 'N' && str[i + 1] == 'O')
			return (false);
		if (str[i] == 'F')
			return (false);
		if (str[i] == 'C')
			return (false);
		if (str[i] == '1' || str[i] == '0' || str[i] == '\0' || ft_isspace(str[i]))
			return (true);
		i++;
	}
	if (!str[i] || str[i] == ft_isspace(str[i]))
		return (true);
	return (false);
}

int	check_double_param(t_data *data)
{
	int			i;
	int			j;
	static bool	dejavu[256] = {false};

	i = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i] && ft_isspace(data->file[i][j]))
			j++;
		if (dejavu[(unsigned char)data->file[i][j]])
		{
			return (ft_putstr_fd("Error\nCUB3D : double param detected!\n", 2), \
				ERROR);
		}
		if (update_dejavu(data->file, i, j, dejavu) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static int	update_dejavu(char **file, int i, int j, bool *dejavu)
{
	if (file[i][j] == 'N' && file[i][j + 1] == 'O')
		dejavu['N'] = true;
	else if (file[i][j] == 'S' && file[i][j + 1] == 'O')
		dejavu['S'] = true;
	else if (file[i][j] == 'W' && file[i][j + 1] == 'E')
	{
		dejavu['W'] = true;
	}
	else if (file[i][j] == 'E' && file[i][j + 1] == 'A')
		dejavu['E'] = true;
	else if (file[i][j] == 'F' && file[i][j + 1] == ' ')
		dejavu['F'] = true;
	else if (file[i][j] == 'C' && file[i][j + 1] == ' ')
		dejavu['C'] = true;
	return (SUCCESS);
}
