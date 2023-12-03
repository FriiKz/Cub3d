/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:24:58 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 15:57:46 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_longest(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

unsigned int	get_pixel(t_data *img, int x, int y)
{
	char	*dest;

	if (x <= 0 || x >= 32 || y <= 0 || y >= 32)
		return (1);
	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dest);
}

int	check_input(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '.')
		i++;
	if (ft_strcmp(av[1], ".cub") == 0)
		return (1);
	else
		return (0);
}

void	boh6(t_items *it)
{
	if (it->disv < it->dish)
	{
		it->shade = 0.5;
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
	it->lineh = (64 * 640) / (it->dist);
	it->ty_step = 32.0 / (float)it->lineh;
	it->ty_off = 0;
}

void	boh7(t_items *it)
{
	if (it->shade == 1)
	{
		it->hmt = 0;
		it->tx = (int)(it->rx / 2.0) % 32;
		if (it->ra > 180)
		{
			it->tx = 32 - it->tx;
			it->hmt = 1;
		}
	}
	else
	{
		it->tx = (int)(it->ry / 2.0) % 32;
		it->hmt = 3;
		if (it->ra > 90 && it->ra < 270)
		{
			it->hmt = 2;
			it->tx = 32 - it->tx;
		}
	}
}
