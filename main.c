/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:54:16 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/08 03:23:38 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int		main(int ac, char **av)
{
	t_fdf *data;

	if (ac == 1)
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->altitude = 1;
	data->change_x = 500;
	data->change_y = 100;
	data->isometric = 1;
	data->zoom = 50;
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
