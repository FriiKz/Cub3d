/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROVA.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:36:19 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 19:08:34 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	it->m = lineOff;
	while (it->m < lineOff + lineH)
	{
		it->n = 0;
		while (it->n <= it->thickness)
		{
			if (it->hmt == 0)
				my_mlx_pixel_put(it, r * 8 + it->n, it->m, \
				get_pixel(it->textures->no, it->tx, it->ty));
			else if (it->hmt == 3)
				my_mlx_pixel_put(it, r * 8 + it->n, it->m, \
				get_pixel(it->textures->ea, it->tx, it->ty));
			else if (it->hmt == 1)
				my_mlx_pixel_put(it, r * 8 + it->n, it->m, \
				get_pixel(it->textures->so, it->tx, it->ty));
			else if (it->hmt == 2)
				my_mlx_pixel_put(it, r * 8 + it->n, it->m, \
				get_pixel(it->textures->we, it->tx, it->ty));
			it->n++;
		}
		it->ty += it->ty_step;
		it->m++;
	}
}

char	**xd(t_items *it)
{
	xd_helper2(it);
	while (it->a1 < it->a4)
	{
		it->new_matrix[it->a1] = calloc(it->a4, sizeof(char *));
		if (!it->new_matrix[it->a1])
		{
			it->a2 = 0;
			while (it->a2 < it->a1)
			{
				free(it->new_matrix[it->a2]);
				it->a2++;
			}
			free(it->new_matrix);
			return (NULL);
		}
		xd_helper3(it);
	}
	xd_helper(it);
	return (it->new_matrix);
}

void	main_helper(t_items *it)
{
	initializer(it);
	it->y_max = line_counter(it);
	readfile(it);
	it->x_max = column_counter(it);
	if (it->x_max != it->y_max)
		it->matrix = xd(it);
	printmatrix(it);
	if (!validate_map(it))
	{
		printf("MAPP ERROR\n");
		ft_exit(it);
	}
	player_pos(it);
	initializer2(it);
	load_texture(it);
	draw_rays_2d(it);
	floor_rgb(it);
	ceiling_rgb(it);
}

int	main(int ac, char **av)
{
	t_items	it;

	if (ac == 2 && check_input(av) == 1)
	{
		it.map = av[1];
		main_helper(&it);
		mlx_hook(it.win, 2, (1L << 0), button_down, &it);
		mlx_hook(it.win, 3, 1L << 1, button_up, &it);
		mlx_loop_hook(it.mlx, movement, &it);
		mlx_hook(it.win, 17, 1L << 16, ft_exit, &it);
		mlx_loop(it.mlx);
	}
	else
		printf("Map error!\n");
	return (0);
}
