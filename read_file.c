/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:21:16 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/08 03:23:48 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(file, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int		get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_countwords(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_z(int *z_line, char *line, int w)
{
	char	**num;
	int		i;

	i = 0;
	num = ft_strsplit(line, ' ');
	while (w--)
	{
		z_line[i] = ft_atoi(num[i]);
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file);
	data->width = get_width(file);
	data->z = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while (i < data->height)
	{
		data->z[i] = (int *)malloc(sizeof(int) * (data->width));
		i++;
	}
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0 && i < data->height)
	{
		fill_z(data->z[i], line, data->width);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
