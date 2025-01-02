/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:51:14 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/01 15:14:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_invalid_param(t_data *data);

int	check_valid_fd(t_data *data)
{
	if (check_NO(data) == ERROR)
		return (ERROR);
	if (check_SO(data) == ERROR)
		return (ERROR);
	if (check_WE(data) == ERROR)
		return (ERROR);
	if (check_EA(data) == ERROR)
		return (ERROR);
	if (check_F(data) == ERROR)
		return (ERROR);
	if (check_C(data) == ERROR)
		return (ERROR);
	if (check_map(data) == ERROR)
		return (ERROR);
	if (check_double_param(data) == ERROR)
		return (ERROR);
	if (check_invalid_param(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
