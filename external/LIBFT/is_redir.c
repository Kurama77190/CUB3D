/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:05:17 by sben-tay          #+#    #+#             */
/*   Updated: 2024/10/19 16:10:37 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_redir(char c)
{
	return (c == '<' || c == '>' || c == ' ' || c == '\n' || c == '\v' \
		|| c == '\t' || c == '\r');
}
