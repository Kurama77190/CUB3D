/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:54:39 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/04 05:58:31 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgb(t_data *data, char *line, char **c, char **f);
static int	get_path_wall(t_data *data, char *line);
static int	get_int_rgb(t_data *data, char *c, char *f);

int	get_value_fd(t_data *data)
{
	int		i;
	char	*c_rgb;
	char	*f_rgb;

	c_rgb = NULL;
	f_rgb = NULL;
	i = 0;
	while (data->file[i])
	{
		if (get_path_wall(data, data->file[i]) == ERROR)
			return (ERROR);
		if (get_rgb(data, data->file[i], &c_rgb, &f_rgb) == ERROR)
			return (ERROR);
		i++;
	}
	if (get_int_rgb(data, c_rgb, f_rgb) == ERROR)
		return (ERROR);
	ft_free((void **)&f_rgb);
	ft_free((void **)&c_rgb);
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
		data->parsing.no = ft_strtrim_space(line + (i + 2));
		return (SUCCESS);
	}
	else if (line[i] == 'S' && line[i + 1] == 'O')
	{
		data->parsing.so = ft_strtrim_space(line + (i + 2));
		return (SUCCESS);
	}
	else if (line[i] == 'W' && line[i + 1] == 'E')
	{
		data->parsing.we = ft_strtrim_space(line + (i + 2));
		return (SUCCESS);
	}
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (data->parsing.ea = ft_strtrim_space(line + (i + 2)), (SUCCESS));
	return (SUCCESS);
}

static int	get_rgb(t_data *data, char *line, char **C_RGB, char **F_RGB)
{
	int	i;

	(void)data;
	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == 'F')
	{
		*F_RGB = ft_strtrim_space(line + (i + 1));
		return (SUCCESS);
	}
	else if (line[i] == 'C')
	{
		*C_RGB = ft_strtrim_space(line + (i + 1));
		return (SUCCESS);
	}
	return (SUCCESS);
}

static int	get_int_rgb(t_data *data, char *c, char *f)
{
	char	**tab;

	tab = ft_split(f, ',');
	if (!tab)
		return (ERROR);
	data->parsing.r_f = ft_atoi(tab[0]);
	data->parsing.g_f = ft_atoi(tab[1]);
	data->parsing.b_f = ft_atoi(tab[2]);
	free_split(tab);
	tab = ft_split(c, ',');
	if (!tab)
		return (ERROR);
	data->parsing.r_c = ft_atoi(tab[0]);
	data->parsing.g_c = ft_atoi(tab[1]);
	data->parsing.b_c = ft_atoi(tab[2]);
	free_split(tab);
	return (SUCCESS);
}
