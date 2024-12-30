/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:00:38 by sben-tay          #+#    #+#             */
/*   Updated: 2024/12/30 12:51:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (handle_parsing(argc, argv, &data) == ERROR)
		return (ERROR);
	int i = 0;
	while (data.file[i])
	{
		printf("%s\n", data.file[i]);
		i++;
	}
	printf("parsing done\n");
	ft_free_all(&data);
}

// go finir l ecole 42 !!

// cette ete je pars en stage !!