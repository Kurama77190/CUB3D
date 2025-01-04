/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:00:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/04 05:04:09 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tab(char **str);
void	print_value_fd(t_data *data);

int main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (handle_parsing(argc, argv, &data) == ERROR)
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}
	// print_tab(data.parsing.map);
	print_value_fd(&data);
	printf("parsing done\n");
	ft_free_all(&data);
	return (0);
}


void	print_tab(char **str)
{
	int i = 0;
	while (str[i])
	{
		printf("%s", str[i]);
		i++;
	}
	return ; 
}

void	print_value_fd(t_data *data)
{
	printf("NO: %s\n", data->parsing.no);
	printf("SO: %s\n", data->parsing.so);
	printf("WE: %s\n", data->parsing.we);
	printf("EA: %s\n", data->parsing.ea);
	printf("C: %s\n", data->parsing.c);
	printf("F: %s\n", data->parsing.f);
	// printf("pos_x: %d\n", data->parsing.pos_x);
	// printf("pos_y: %d\n", data->parsing.pos_y);
	// printf("direction: %s\n", data->parsing.direction);
	
}