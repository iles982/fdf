/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:29:14 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/08 03:23:14 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data)
{
	int		max;

	data->z_altitude = data->z[(int)data->y][(int)data->x] * data->altitude;
	data->z_altitude1 = data->z[(int)data->y1][(int)data->x1] * data->altitude;
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	if (data->isometric == 1)
		isometric(data);
	change_data(data);
	data->x_step = data->x1 - data->x;
	data->y_step = data->y1 - data->y;
	max = MAX1(MOD(data->x_step), MOD(data->y_step));
	data->x_step /= max;
	data->y_step /= max;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y,
		find_color(data));
		data->x += data->x_step;
		data->y += data->y_step;
	}
}

int		find_color(t_fdf *data)
{
	int		color;

	color = 12738273 + data->z_altitude * 22222;
	return (color);
}

void	change_data(t_fdf *data)
{
	data->x += data->change_x;
	data->y += data->change_y;
	data->x1 += data->change_x;
	data->y1 += data->change_y;
}

void	isometric(t_fdf *data)
{
	data->x = (data->x - data->y) * cos(1);
	data->y = (data->x + data->y) * sin(1) - data->z_altitude;
	data->x1 = (data->x1 - data->y1) * cos(1);
	data->y1 = (data->x1 + data->y1) * sin(1) - data->z_altitude1;
}

void	draw_map(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	printconfig(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				get_x_data(data, x, y);
				draw(data);
			}
			if (y < data->height - 1)
			{
				get_y_data(data, x, y);
				draw(data);
			}
			x++;
		}
		y++;
	}
}
