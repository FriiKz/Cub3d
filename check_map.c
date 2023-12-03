/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:37:29 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 18:37:31 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_val_pos(int y_max, int x_max, int x, int y)
{
	return (x >= 0 && x < y_max && y >= 0 && y < x_max);
}

void	queue_init(t_items *it)
{
	it->queue_x = malloc(sizeof(int) * (it->y_max * it->x_max));
	if (!it->queue_x)
		return ;
	it->queue_y = malloc(sizeof(int) * (it->y_max * it->x_max));
	if (!it->queue_y)
		return ;
}

void	free_struct(t_items *it)
{
	free(it->queue_x);
	free(it->queue_y);
	free(it->dx);
	free(it->dy);
}

int	is_zero_enclosed_by_one(t_items *it)
{
	is_zero_init(it);
	while (it->i < it->y_max)
	{
		it->j = 0;
		while (it->j < it->x_max)
		{
			if (it->matrix[it->i][it->j] == '0' && !it->visited[it->i][it->j])
			{
				is_zero_helper4(it);
				if (it->is_enclosed)
					continue ;
				else
				{
					free_struct(it);
					return (0);
				}
			}
			it->j++;
		}
		it->i++;
	}
	free_struct(it);
	return (1);
}

int	validate_map(t_items *it)
{
	it->player_position_found = 0;
	valid_char_init(it);
	it->u = 0;
	while (it->u < it->y_max)
	{
		it->v = 0;
		while (it->v < it->x_max)
		{
			is_map_helper(it);
			if (!it->is_valid_char)
				return (0);
			if (it->current_char == 'N' || it->current_char == 'S' || \
				it->current_char == 'E' || it->current_char == 'W')
				it->player_position_found ++;
			it->v++;
		}
		it->u++;
	}
	if (it->player_position_found != 1)
		return (0);
	if (is_zero_enclosed_by_one(it) == 0)
		return (0);
	return (1);
}
