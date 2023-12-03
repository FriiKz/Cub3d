/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:38:22 by aliburdi          #+#    #+#             */
/*   Updated: 2023/12/03 18:33:16 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_helper(t_items *it)
{
	if (it->matrix[it->p][it->q] == 'N')
	{
		it->px = (it->q * 64) + 32;
		it->py = (it->p * 64) + 32;
		it->pa = 90;
	}
	if (it->matrix[it->p][it->q] == 'W')
	{
		it->px = (it->q * 64) + 32;
		it->py = (it->p * 64) + 32;
		it->pa = 180;
	}
	if (it->matrix[it->p][it->q] == 'S')
	{
		it->px = (it->q * 64) + 32;
		it->py = (it->p * 64) + 32;
		it->pa = 270;
	}
}

void	player_pos(t_items *it)
{
	it->p = 0;
	while (it->p < it->y_max)
	{
		it->q = 0;
		while (it->q < it->x_max)
		{
			player_helper(it);
			if (it->matrix[it->p][it->q] == 'E')
			{
				it->px = (it->q * 64) + 32;
				it->py = (it->p * 64) + 32;
				it->pa = 0;
			}
			it->q++;
		}
		it->p++;
	}
}
