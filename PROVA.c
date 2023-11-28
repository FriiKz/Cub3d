/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROVA.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:22:43 by aliburdi          #+#    #+#             */
/*   Updated: 2023/11/28 11:57:33 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// unsigned int	get_pixel(t_items *it, int x, int y)
// {
// 	char	*dest;

// 	if (x <= 0 || x >= 64 || y <= 0 || y >= 64)
// 		return (1);
// 	dest = it->addr + (y * it->line_length + x * (it->bits_per_pixel / 8));
// 	return (*(unsigned int *)dest);
// }

// static t_data *load(t_data *mlx, char *s)
// {
// 	t_data	*data;
// 	int		a;
// 	int		b;

// 	data = malloc(sizeof(t_data));
// 	a = 64;
// 	b = 64;
// 	data->img = mlx_png_file_to_image(mlx->mlx_ptr, s, &a, &b);
// 	if (data->img == NULL)
// 	{
// 		free(data);
// 		return (NULL);
// 	}
// 	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
// 			&data->line_length, &data->endian);
// 	return (data);

// }

// void	ft_create_level(t_data *mlx)
// {
// 	mlx->map->textures = malloc(sizeof(t_textures));
// 	mlx->map->textures->ea = load(mlx, "src/wall_ea.png");
// 	mlx->map->textures->no = load(mlx, "src/wall_no.png");
// 	mlx->map->textures->so = load(mlx, "src/wall_so.png");
// 	mlx->map->textures->we = load(mlx, "src/wall_we.png");
// 	mlx->map->color = 0x00FFFF;
// 	mlx->map->depth = (int *)malloc(sizeof(float) * 1200);
// 	ft_map_convert(mlx);
// 	ft_get_player_pos(mlx);
// 	mlx->map->pa = 90;
// 	mlx->map->pdx = cos(degtorad(mlx->map->pa));
// 	mlx->map->pdy = -sin(degtorad(mlx->map->pa));
// 	printf("player found at x: %f y: %f\n", mlx->map->px, mlx->map->py);
// 	mlx_loop_hook(mlx->mlx_ptr, ft_draw, mlx);

// }

void	draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (1)
	{
		mlx_pixel_put(mlx, win, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_3d_wall(t_items *it, int r, float lineOff, float lineH)
{
	int	color;

	for (int y = lineOff; y < lineOff + lineH; y++)
	{
		for (int i = 0; i <= it->thickness; i++)
		{
			color = 0xFF0000;
			my_mlx_pixel_put(it, r * 8 + i, y, color);
		}
	}
}

void	draw_ceiling(t_items *it)
{
	int	y;
	int	x;

	y = 0;
	while (y < 280)
	{
		x = 0;
		while (x < 960)
		{
			my_mlx_pixel_put(it, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_items *it)
{
	int	y;
	int	x;

	y = 280;
	while (y < 640)
	{
		x = 0;
		while (x < 960)
		{
			my_mlx_pixel_put(it, x, y, 0x00F00F);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_items	it;

	if (ac == 2)
	{
		it.map = av[1];
		initializer(&it);
		it.y_max = line_counter(&it);
		readfile(&it);
		it.x_max = column_counter(&it);
		printf("%s\n%s\n%s\n%s\n%s\n%s\n", it.no, it.so, it.ea, it.we, it.floor, it.ceiling);
		draw_rays_2d(&it);
		mlx_hook(it.win, 2, (1L << 0), button_down, &it);
		mlx_hook(it.win, 3, 1L << 1, button_up, &it);
		mlx_loop_hook(it.mlx, movement, &it);
		mlx_hook(it.win, 17, 1L << 16, ft_exit, &it);
		mlx_loop(it.mlx);
	}
	return (0);
}
