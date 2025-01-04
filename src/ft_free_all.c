/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:49:40 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/04 05:58:48 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_parsing(t_data *data);

void	ft_free_all(t_data *data)
{
	ft_free_parsing(data);
	// ft_free_exec(data);
}


static void	ft_free_parsing(t_data *data)
{
	free_split(data->file);
	ft_free((void **)&data->parsing.no);
	ft_free((void **)&data->parsing.so);
	ft_free((void **)&data->parsing.we);
	ft_free((void **)&data->parsing.ea);
	free_split(data->parsing.map);
}

// static void ft_free_exec(t_data *data)
// {
// 	// t'es fonction a liberer ici utilise ft_free((void **)&ptr); pour liberer la memoire
// }
