/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:43:24 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/08 03:23:22 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
{
	deal_key_2(key, data);
	if (key == 8)
	{
		if (data->altitude >= 2)
			data->altitude--;
	}
	if (key == 9)
		data->altitude++;
	if (key == 53)
	{
		exit(0);
		free(data);
	}
	if (key == 126 || key == 125 || key == 124 || key == 123 || key == 11 ||
	key == 13 || key == 1 || key == 6 || key == 7 || key == 8 || key == 9)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_map(data);
	}
	return (0);
}

int		deal_key_2(int key, t_fdf *data)
{
	if (key == 126)
		data->change_y -= 10;
	if (key == 125)
		data->change_y += 10;
	if (key == 124)
		data->change_x += 10;
	if (key == 123)
		data->change_x -= 10;
	if (key == 13)
		data->zoom += 3;
	if (key == 1)
	{
		if (data->zoom >= 3)
			data->zoom -= 3;
	}
	if (key == 6)
		data->isometric = 0;
	if (key == 7)
		data->isometric = 1;
	return (0);
}
