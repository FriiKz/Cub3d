/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:25:15 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 18:17:25 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dx(t_items *it)
{
	it->dx = malloc(sizeof(int) * 8);
	if (!it->dx)
		return ;
	it->dx[0] = -1;
	it->dx[1] = -1;
	it->dx[2] = -1;
	it->dx[3] = 0;
	it->dx[4] = 0;
	it->dx[5] = 1;
	it->dx[6] = 1;
	it->dx[7] = 1;
}

void	init_dy(t_items *it)
{
	it->dy = malloc(sizeof(int) * 8);
	if (!it->dy)
		return ;
	it->dy[0] = -1;
	it->dy[1] = -1;
	it->dy[2] = -1;
	it->dy[3] = 0;
	it->dy[4] = 0;
	it->dy[5] = 1;
	it->dy[6] = 1;
	it->dy[7] = 1;
}

void	valid_char_init(t_items *it)
{
	it->valid_chars[0] = '7';
	it->valid_chars[1] = ' ';
	it->valid_chars[2] = '0';
	it->valid_chars[3] = '1';
	it->valid_chars[4] = 'N';
	it->valid_chars[5] = 'S';
	it->valid_chars[6] = 'E';
	it->valid_chars[7] = 'W';
}

void	is_map_helper(t_items *it)
{
	it->current_char = it->matrix[it->u][it->v];
	it->is_valid_char = false;
	it->z = 0;
	while (it->valid_chars[it->z] != '\0')
	{
		if (it->current_char == it->valid_chars[it->z])
		{
			it->is_valid_char = true;
			break ;
		}
		it->z++;
	}
}
