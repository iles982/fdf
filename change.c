/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:58:58 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/08 03:22:58 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_y_data(t_fdf *data, int x, int y)
{
	data->x = x;
	data->y = y;
	data->x1 = x;
	data->y1 = data->y + 1;
}

void	get_x_data(t_fdf *data, int x, int y)
{
	data->x = x;
	data->y = y;
	data->x1 = data->x + 1;
	data->y1 = y;
}

void	printconfig(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 30, 32738273,
	"Use arrows to move it");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 45, 12738273,
	"Press 'S' to reduce");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 60, 12738273,
	"Press 'W' to enlarge");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 75, 42738273,
	"Press 'Z' to make parallel projection");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 90, 42738273,
	"Press 'X' to make isometric projection");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 105, 42738273,
	"Press 'C' to make altitude++");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 120, 42738273,
	"Press 'V' to make altitude--");
}
