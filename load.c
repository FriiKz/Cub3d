/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:01:12 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 15:23:20 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*load(t_items *it, char *s)
{
	t_data	*data;
	int		b;

	data = malloc(sizeof(t_data));
	b = 32;
	data->img = mlx_xpm_file_to_image(it->mlx, s, &b, &b);
	if (data->img == NULL)
	{
		free(data);
		return (NULL);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (data);
}

void	load_texture(t_items *it)
{
	it->textures->ea = load(it, it->ea);
	it->textures->no = load(it, it->no);
	it->textures->so = load(it, it->so);
	it->textures->we = load(it, it->we);
}
