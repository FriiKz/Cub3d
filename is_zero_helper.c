/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:55:10 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 17:55:50 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_zero_helper2(t_items *it)
{
	it->b = it->queue_x[it->front];
	it->c = it->queue_y[it->front];
	it->front++;
	it->k = 0;
}

void	is_zero_helper(t_items *it)
{
	while (it->front != it->rear)
	{
		is_zero_helper2(it);
		while (it->k < 8)
		{
			it->nx = it->b + it->dx[it->k];
			it->ny = it->c + it->dy[it->k];
			if (is_val_pos(it->y_max, it->x_max, it->nx, it->ny) \
				&& it->matrix[it->nx][it->ny] == '0' \
				&& !it->visited[it->nx][it->ny])
			{
				it->visited[it->nx][it->ny] = true;
				it->queue_x[it->rear] = it->nx;
				it->queue_y[it->rear] = it->ny;
				it->rear++;
			}
			else if (!is_val_pos(it->y_max, it->x_max, \
				it->nx, it->ny) \
				|| it->matrix[it->nx][it->ny] == '7')
			{
				it->is_enclosed = false;
			}
			it->k++;
		}
	}
}

void	is_zero_helper3(t_items *it)
{
	while (it->i < it->y_max)
	{
		it->j = 0;
		while (it->j < it->x_max)
		{
			it->visited[it->i][it->j] = false;
			it->j++;
		}
		it->i++;
	}
	it->i = 0;
}

void	is_zero_helper4(t_items *it)
{
	it->is_enclosed = true;
	it->visited[it->i][it->j] = true;
	queue_init(it);
	it->front = 0;
	it->rear = 0;
	it->queue_x[it->rear] = it->i;
	it->queue_y[it->rear] = it->j;
	it->rear++;
	is_zero_helper2(it);
}

void	is_zero_init(t_items *it)
{
	it->i = 0;
	it->j = 0;
	init_dx(it);
	init_dy(it);
	is_zero_helper3(it);
}
