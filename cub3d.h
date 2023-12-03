/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:52:37 by aliburdi          #+#    #+#             */
/*   Updated: 2023/12/03 19:06:55 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdarg.h>
# include <fcntl.h>
# include "minilibX/mlx.h"
# include "get_next_line/get_next_line_bonus.h"
# include <string.h>
# include <stdbool.h>

# define MAPS 64
# define PI 3.14159
# define M_PI 3.14159265358979323846

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_textures {
	t_data	*ea;
	t_data	*no;
	t_data	*so;
	t_data	*we;
}	t_textures;

typedef struct s_items
{
	void		*mlx;
	void		*win;
	float		px;
	float		py;
	float		pdx;
	float		pdy;
	float		pa;
	float		shade;
	float		ty_step;
	float		ty_off;
	float		ty;
	float		tx;
	void		*img;
	void		*ea_texture;
	void		*we_texture;
	void		*so_texture;
	void		*no_texture;
	char		*addr;
	char		*map;
	char		*file;
	char		**matrix;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*floor;
	int			red_f;
	int			green_f;
	int			blue_f;
	char		*ceiling;
	char		valid_chars[7];
	int			red_c;
	int			green_c;
	int			blue_c;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			thickness;
	int			vmt;
	int			hmt;
	int			nx;
	int			ny;
	int			k;
	int			b;
	int			c;
	int			i;
	int			j;
	int			x;
	int			y;
	int			w;
	int			a;
	int			s;
	int			d;
	int			u;
	int			v;
	int			z;
	int			p;
	int			q;
	int			m;
	int			n;
	char		**new_matrix;
	int			a1;
	int			a2;
	int			a3;
	int			a4;
	int			esc;
	int			x0;
	int			y0;
	int			ipx;
	int			ipx_add_x0;
	int			ipx_sub_x0;
	int			ipy;
	int			ipy_add_y0;
	int			ipy_sub_y0;
	int			x_max;
	int			y_max;
	int			r;
	int			mx;
	int			my;
	int			mp;
	int			dof;
	int			*dx;
	int			*dy;
	int			*queue_x;
	int			*queue_y;
	float		vx;
	float		vy;
	float		rx;
	float		ry;
	float		ra;
	float		xo;
	float		yo;
	float		dist;
	float		disv;
	float		tang;
	float		dish;
	float		hx;
	float		hy;
	float		ca;
	int			lineh;
	float		lineoff;
	bool		is_enclosed;
	int			player_position_found;
	char		current_char;
	int			front;
	int			rear;
	bool		visited[2000][2000];
	bool		is_valid_char;
	t_textures	*textures;
}				t_items;

void			load_texture(t_items *it);
void			initializer(t_items *it);
void			matrix_c(t_items *it);
void			free_matrix(t_items *it);
void			printmatrix(t_items *it);
void			ft_clear(t_items *it);
void			my_mlx_pixel_put(t_items *it, int x, int y, int color);
void			draw_rays_2d(t_items	*it);
void			draw_3d_wall(t_items *it, int r, float lineOff, float lineH);
void			draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2, int color);
void			draw_map2d(t_items *it);
void			draw_player_2d(t_items *it);
void			read_rgb(t_items *it);
void			floor_rgb(t_items *it);
void			ceiling_rgb(t_items *it);
void			player_pos(t_items *it);
void			initializer2(t_items *it);
void			movement_helper1(t_items *it);
void			movement_helper2(t_items *it);
int				is_zero_enclosed_by_one(t_items *it);
int				validate_map(t_items *it);
int				ft_strcmp(char *s1, char *s2);
int				line_counter(t_items *it);
int				column_counter(t_items *it);
float			fix_ang(float a);
int				movement(t_items *it);
int				button_up(int key, t_items *it);
int				button_down(int key, t_items *it);
int				ft_exit(t_items *it);
int				create_rgb(int red, int green, int blue);
void			main_helper(t_items *it);
float			distance(float ax, float ay, float bx, float by);
int				ft_atoi(const char *str);
float			deg_to_rad(float a);
void			draw_floor(t_items *it);
void			draw_ceiling(t_items *it);
void			file_check(t_items *it);
void			readfile(t_items *it);
char			*ft_strdup(char *s1);
void			printmatrix(t_items *it);
char			*check_line(char *str);
void			init_dy(t_items *it);
void			init_dx(t_items *it);
void			boh(t_items *it);
void			boh2(t_items *it);
void			boh3(t_items *it);
void			boh4(t_items *it);
void			boh5(t_items *it);
void			boh6(t_items *it);
void			boh7(t_items *it);
void			player_helper(t_items *it);
void			is_map_helper(t_items *it);
void			xd_helper(t_items *it);
void			xd_helper2(t_items *it);
void			xd_helper3(t_items *it);
char			**ft_split(const char *s, char c);
int				check_input(char **av);
unsigned int	get_pixel(t_data *img, int x, int y);
size_t			ft_longest(int x, int y);
void			is_zero_helper(t_items *it);
void			is_zero_helper2(t_items *it);
void			is_zero_helper3(t_items *it);
void			is_zero_helper4(t_items *it);
void			is_zero_init(t_items *it);
void			queue_init(t_items *it);
bool			is_val_pos(int y_max, int x_max, int x, int y);
void			valid_char_init(t_items *it);
// int		check_input(int key, t_items *it);
// void	fd_check(t_items *it);
#endif
