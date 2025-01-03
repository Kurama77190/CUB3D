/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:00:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/03 18:55:51 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (handle_parsing(argc, argv, &data) == ERROR)
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}
	int i = 0;
	while (data.parsing.map[i])
	{
		printf("%s", data.parsing.map[i]);
		i++;
	}
	printf("parsing done\n");
	ft_free_all(&data);
	return (0);
}

