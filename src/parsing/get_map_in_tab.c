/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:12:18 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/02 00:26:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d,h"

static int	alloc_and_cpy(t_data *data);
static int	len_map(t_data *data);
static bool	is_char_map(char c);
static char	*first_line(t_data *data)

int	get_map_in_tab(t_data *data)
{
	alloc_and_cpy(data);
	// verifier que la map est valide
	// verifier que la map est fermee
	// verifier que la map est entouree de murs
}

static int	alloc_and_cpy(t_data *data)
{
	int	len;
	int	first_line;

	len = len_map(data);
	first_line = first_line(data);
	if (first_line == NULL)
		return (ft_putstr_fd("CUB3D: MAP not found.\n", 2), ERROR);
	data->parsing.map = malloc(sizeof(char *) * (len + 1));
	if (data->parsing.map == NULL)
		return (ERROR);
	while (data->file[len])
	{
		
	}
}

static int	len_map(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (data->file[i])
		i++;
	while(data->file[i][0] != '\n')
	{
		i--;
		len++;
	}
	return (len);
}

static char	*first_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file[i][j])
		i++;
	while(!data->file[i][0] && !is_char_map(data->file[i][0]))
		i--;
	{
		j = 0;	
		while(data->file[i][j] && ft_isspace(data->file[i][j]))
			j++;
		if (is_char_map(data->file[i][j]))
			return (data->file[i]);
		i--;
	}
	return (NULL);
}

static bool	is_char_map(char c)
{
	return (c == ' ' || c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '\n');
}
