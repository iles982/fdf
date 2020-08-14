/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:54:11 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/08 03:22:49 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef struct s_fdf
{
	int			width;
	int			height;
	int			**z;
	int			zoom;
	int			color;
	int			change_x;
	int			change_y;
	int			isometric;
	int			altitude;
	int			z_altitude;
	int			z_altitude1;
	float		x1;
	float		y1;
	float		x;
	float		y;
	float		x_step;
	float		y_step;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

int		deal_key_2(int key, t_fdf *data);
void	get_y_data(t_fdf *data, int x, int y);
void	get_x_data(t_fdf *data, int x, int y);
void	printconfig(t_fdf *data);
void	isometric(t_fdf *data);
int		get_height(char *file);
int		get_width(char *file);
void	fill_z(int *z_line, char *line, int w);
void	read_file(char *file, t_fdf *data);
void	draw(t_fdf *data);
void	draw_map(t_fdf *data);
int		deal_key(int key, t_fdf *data);
int		find_color(t_fdf *data);
void	change_data(t_fdf *data);

#endif