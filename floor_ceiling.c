/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:19:36 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 15:51:34 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_items *it)
{
	int	y;
	int	x;
	int	color;

	color = create_rgb(it->red_f, it->green_f, it->blue_f);
	y = 280;
	while (y < 640)
	{
		x = 0;
		while (x < 960)
		{
			my_mlx_pixel_put(it, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_ceiling(t_items *it)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	color = create_rgb(it->red_c, it->green_c, it->blue_c);
	while (y < 320)
	{
		x = 0;
		while (x < 960)
		{
			my_mlx_pixel_put(it, x, y, color);
			x++;
		}
		y++;
	}
}

void	floor_rgb(t_items *it)
{
	char	**rgb;

	rgb = ft_split(it->floor, ',');
	it->red_f = ft_atoi(rgb[0]);
	it->green_f = ft_atoi(rgb[1]);
	it->blue_f = ft_atoi(rgb[2]);
}

void	ceiling_rgb(t_items *it)
{
	char	**rgb;

	rgb = ft_split(it->ceiling, ',');
	it->red_c = ft_atoi(rgb[0]);
	it->green_c = ft_atoi(rgb[1]);
	it->blue_c = ft_atoi(rgb[2]);
}

int	create_rgb(int red, int green, int blue)
{
	int	color;

	if (red > 255)
		red = 255;
	if (red < 0)
		red = 0;
	if (green > 255)
		green = 255;
	if (green < 0)
		green = 0;
	if (blue > 255)
		blue = 255;
	if (blue < 0)
		blue = 0;
	color = (red << 16) | (green << 8) | blue;
	return (color);
}
