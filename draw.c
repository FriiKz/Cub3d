/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aliburdi <aliburdi@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/23 14:35:59 by aliburdi		  #+#	#+#			 */
/*   Updated: 2023/11/25 15:15:06 by aliburdi		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays_2d(t_items	*it)
{
	it->ra = fix_ang(it->pa + 30);
	it->r = 0;
	while (it->r < 120)
	{
		it->dof = 0;
		it->disv = 1000000;
		it->tang = tan(deg_to_rad(it->ra));
		if (cos(deg_to_rad(it->ra)) > 0.001)
		{
			it->rx = (((int)it->px / 64) * 64) + 64;
			it->ry = (it->px - it->rx) * it->tang + it->py;
			it->xo = 64;
			it->yo = -it->xo * it->tang;
		}
		else if (cos(deg_to_rad(it->ra)) < -0.001)
		{
			it->rx = (((int)it->px / 64) * 64) - 0.0001;
			it->ry = (it->px - it->rx) * it->tang + it->py;
			it->xo = -64;
			it->yo = -it->xo * it->tang;
		}
		else
		{
			it->rx = it->px;
			it->ry = it->py;
			it->dof = 10;
		}
		while (it->dof < 10)
		{
			it->mx = (int)(it->rx) / 64;
			it->my = (int)(it->ry) / 64;
			it->mp = it->my * it->x_max + it->mx;
			if (it->mp > 0 && it->mp < it->x_max * it->y_max && \
				it->matrix[it->mp / it->x_max][it->mp % it->x_max] == '1')
			{
				it->dof = 10;
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
		it->vx = it->rx;
		it->vy = it->ry;
		it->dof = 0;
		it->dish = 1000000;
		it->hx = it->px;
		it->hy = it->py;
		it->tang = 1.0 / it->tang;
		if (sin(deg_to_rad(it->ra)) > 0.001)
		{
			it->ry = (((int)it->py / 64) * 64) - 0.0001;
			it->rx = (it->py - it->ry) * it->tang + it->px;
			it->yo = -64;
			it->xo = -it->yo * it->tang;
		}
		else if (sin(deg_to_rad(it->ra)) < -0.001)
		{
			it->ry = (((int)it->py / 64) * 64) + 64;
			it->rx = (it->py - it->ry) * it->tang + it->px;
			it->yo = 64;
			it->xo = -it->yo * it->tang;
		}
		else
		{
			it->ry = it->py;
			it->rx = it->px;
			it->dof = 8;
		}
		while (it->dof < 8)
		{
			it->mx = (int)(it->rx) / 64;
			it->my = (int)(it->ry) / 64;
			it->mp = it->my * it->y_max + it->mx;
			if (it->mp > 0 && it->mp < it->x_max * it->y_max && \
				it->matrix[it->mp / it->x_max][it->mp % it->x_max] == '1')
			{
				it->dof = 8;
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
		if (it->disv < it->dish)
		{
			it->rx = it->vx;
			it->ry = it->vy;
			it->dist = it->disv;
		}
		if (it->dish < it->disv)
		{
			it->rx = it->hx;
			it->ry = it->hy;
			it->dist = it->dish;
		}
		it->ca = it->pa - it->ra;
		if (it->ca < 0)
			it->ca += 2 * PI;
		if (it->ca > 2 * PI)
			it->ca -= 2 * PI;
		it->dist = it->dist * cos(deg_to_rad(it->ca));
		it->lineh = (MAPS * 640) / (it->dist);
		if (it->lineh > 640)
			it->lineh = 640;
		it->lineoff = 320 - it->lineh / 2.0;
		draw_3d_wall(it, it->r, it->lineoff, it->lineh);
		it->ra = fix_ang(it->ra - 0.5);
		it->r++;
	}
	mlx_put_image_to_window(it->mlx, it->win, it->img, 0, 0);
}

void	draw_map2d(t_items *it)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	for (y = 0; y < it->y_max; y++)
	{
		for (x = 0; x < it->x_max; x++)
		{
			if (it->matrix[y][x] == '1')
			{
				start_x = x * MAPS;
				start_y = y * MAPS;
				end_x = start_x + MAPS;
				end_y = start_y + MAPS;
				for (int i = start_x; i < end_x; i++)
				{
					for (int j = start_y; j < end_y; j++)
						my_mlx_pixel_put(it, i, j, 0xFFFFFF);
				}
			}
		}
	}
	mlx_put_image_to_window(it->mlx, it->win, it->img, 0, 0);
}

void	draw_player_2d(t_items *it)
{
	int	i;
	int	j;

	j = -5;
	while (j < 5)
	{
		i = -5;
		while (i < 5)
		{
			my_mlx_pixel_put(it, it->px + i, it->py + j, 0xFFFF00);
			i++;
		}
		j++;
	}
	my_mlx_pixel_put(it, it->px, it->py, 0xFFFF00);
	draw_line(it->mlx, it->win, it->px, it->py, it->px + \
		it->pdx * 30, it->py + it->pdy * 30, 0xFFFF00);
}
