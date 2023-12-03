/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:22:31 by aliburdi          #+#    #+#             */
/*   Updated: 2023/12/03 15:03:43 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initializer(t_items *it)
{
	it->no = 0;
	it->so = 0;
	it->ea = 0;
	it->we = 0;
	it->mlx = mlx_init();
	it->win = mlx_new_window(it->mlx, 960, 640, "cub3d");
	it->img = mlx_new_image(it->mlx, 960, 640);
	it->addr = mlx_get_data_addr(it->img, &it->bits_per_pixel, \
	&it->line_length, &it->endian);
	it->px = 150;
	it->py = 400;
	it->thickness = 8;
	it->ipx = 0;
	it->ipx_add_x0 = 0;
	it->ipx_sub_x0 = 0;
	it->ipy = 0;
	it->ipy_add_y0 = 0;
	it->ipy_sub_y0 = 0;
	it->x0 = 0;
	it->y0 = 0;
	it->textures = calloc(1, sizeof(t_textures *));
}

void	initializer2(t_items *it)
{
	it->pdx = cos(deg_to_rad(it->pa));
	it->pdy = -sin(deg_to_rad(it->pa));
}

int	ft_exit(t_items *it)
{
	mlx_destroy_window(it->mlx, it->win);
	free_matrix(it);
	exit (0);
	return (0);
}

void	ft_clear(t_items *it)
{
	mlx_destroy_image(it->mlx, it->img);
	it->img = mlx_new_image(it->mlx, 960, 640);
	it->addr = mlx_get_data_addr(it->img, &it->bits_per_pixel, \
	&it->line_length, &it->endian);
}

void	my_mlx_pixel_put(t_items *it, int x, int y, int color)
{
	char	*dst;

	dst = it->addr + (y * it->line_length + x * (it->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
