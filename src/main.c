/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:00:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/01 15:40:57 by sben-tay         ###   ########.fr       */
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
	while (data.file[i])
	{
		printf("%s", data.file[i]);
		i++;
	}
	printf("parsing done\n");
	ft_free_all(&data);
	return (0);
}
