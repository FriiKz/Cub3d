/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:48:18 by aliburdi          #+#    #+#             */
/*   Updated: 2023/12/03 15:59:17 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	boh(t_items *it)
{
	if (cos(deg_to_rad(it->ra)) > 0.001)
	{
		it->rx = (((int)it->px >> 6) << 6) + 64;
		it->ry = (it->px - it->rx) * it->tang + it->py;
		it->xo = 64;
		it->yo = -it->xo * it->tang;
	}
	else if (cos(deg_to_rad(it->ra)) < -0.001)
	{
		it->rx = (((int)it->px >> 6) << 6) - 0.001;
		it->ry = (it->px - it->rx) * it->tang + it->py;
		it->xo = -64;
		it->yo = -it->xo * it->tang;
	}
	else
	{
		it->rx = it->px;
		it->ry = it->py;
		it->dof = 15;
	}
}

void	boh2(t_items *it)
{
	while (it->dof < 15)
	{
		it->mx = (int)(it->rx) >> 6;
		it->my = (int)(it->ry) >> 6;
		it->mp = it->my * it->x_max + it->mx;
		if (it->mp > 0 && it->mp < it->x_max * it->y_max && \
			it->matrix[it->mp / it->x_max][it->mp % it->x_max] == '1')
		{
			it->dof = 15;
			it->disv = cos(deg_to_rad(it->ra)) * (it->rx - it->px) - \
				sin(deg_to_rad(it->ra)) * (it->ry - it->py);
		}
		else
		{
			it->rx += it->xo;
			it->ry += it->yo;
			it->dof += 1;
		}
	}
}

void	boh3(t_items *it)
{
	it->dof = 0;
	it->dish = 1000000;
	it->hx = it->px;
	it->hy = it->py;
	it->tang = 1.0 / it->tang;
	if (sin(deg_to_rad(it->ra)) > 0.001)
	{
		it->ry = (((int)it->py >> 6) << 6) - 0.001;
		it->rx = (it->py - it->ry) * it->tang + it->px;
		it->yo = -64;
		it->xo = -it->yo * it->tang;
	}
	else if (sin(deg_to_rad(it->ra)) < -0.001)
	{
		it->ry = (((int)it->py >> 6) << 6) + 64;
		it->rx = (it->py - it->ry) * it->tang + it->px;
		it->yo = 64;
		it->xo = -it->yo * it->tang;
	}
	else
	{
		it->ry = it->py;
		it->rx = it->px;
		it->dof = 15;
	}
}

void	boh4(t_items *it)
{
	while (it->dof < 15)
	{
		it->mx = (int)(it->rx) >> 6;
		it->my = (int)(it->ry) >> 6;
		it->mp = it->my * it->y_max + it->mx;
		if (it->mp > 0 && it->mp < it->x_max * it->y_max && \
			it->matrix[it->mp / it->x_max][it->mp % it->x_max] == '1')
		{
			it->dof = 15;
			it->hx = it->rx;
			it->hy = it->ry;
			it->dish = cos(deg_to_rad(it->ra)) * (it->rx - it->px) - \
			sin(deg_to_rad(it->ra)) * (it->ry - it->py);
		}
		else
		{
			it->rx += it->xo;
			it->ry += it->yo;
			it->dof += 1;
		}
	}
}

void	boh5(t_items *it)
{
	it->shade = 1;
	boh6(it);
	if (it->lineh > 640)
	{
		it->ty_off = (it->lineh - 640) / 2.0;
		it->lineh = 640;
	}
	it->lineoff = 320 - (it->lineh >> 1);
	it->ty = it->ty_off * it->ty_step;
	boh7(it);
}
