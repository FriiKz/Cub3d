/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:08:11 by lbusi             #+#    #+#             */
/*   Updated: 2023/12/03 19:08:38 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xd_helper(t_items *it)
{
	it->a1 = 0;
	while (it->a1 < it->y_max)
	{
		it->a2 = 0;
		it->a3 = 0;
		while (it->matrix[it->a1][it->a2] && it->a3 < it->x_max)
		{
			if (it->a1 < it->a4 && it->a2 < it->a4)
			{
				if (it->matrix[it->a1][it->a3] == ' ')
					it->a3++;
				it->new_matrix[it->a1][it->a2] = it->matrix[it->a1][it->a3];
			}
			it->a2++;
			it->a3++;
		}
		it->a1++;
	}
	it->x_max = it->a4;
	it->y_max = it->a4;
}

void	xd_helper2(t_items *it)
{
	it->a4 = ft_longest(it->x_max, it->y_max);
	it->new_matrix = calloc(it->a4, sizeof(char **));
	if (!it->new_matrix)
		return ;
	it->a1 = 0;
}

void	xd_helper3(t_items *it)
{
	it->a2 = 0;
	while (it->a2 < it->a4)
	{
		it->new_matrix[it->a1][it->a2] = '7';
		it->a2++;
	}
	it->new_matrix[it->a1][it->a2] = '\0';
	it->a1++;
}
