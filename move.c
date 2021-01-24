/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <hwoodwri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:2.0:54 by hwoodwri          #+#    #+#             */
/*   Updated: 2021/01/16 13:20:53 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_clean_window(t_head *h)
{
	int	i;
	int	j;

	i = 0;
	while(i < h->resol.y)
	{
		j = 0;
		while (j < h->resol.x)
		{
			my_pixel_put(h, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

int move(int keycode, t_head *h)
 {
	//printf("%d\n", keycode);
	double rotation;

	rotation = 0.05;
	ft_clean_window(h);
	if (keycode == W)
	{
		if (h->map[(int)(h->player.y + h->player.dir_y * 0.1)][(int)h->player.x] != '1')
			h->player.y += h->player.dir_y * 0.1;
		if (h->map[(int)h->player.y][(int)(h->player.x + h->player.dir_x * 0.1)] != '1')
			h->player.x += h->player.dir_x * 0.1;
	}
	if (keycode == S)
	{
		if (h->map[(int)(h->player.y - h->player.dir_y * 0.1)][(int)h->player.x] != '1')
			h->player.y -= h->player.dir_y * 0.1;
		if (h->map[(int)h->player.y][(int)(h->player.x - h->player.dir_x * 0.1)] != '1')
			h->player.x -= h->player.dir_x * 0.1;
	}
	if (keycode == A)
	{
		if (h->map[(int)(h->player.y - h->player.dir_x * 0.1)][(int)h->player.x] != '1')
			h->player.y -= h->player.dir_x * 0.1;
		if (h->map[(int)h->player.y][(int)(h->player.x + h->player.dir_y * 0.1)] != '1')
			h->player.x += h->player.dir_y * 0.1;
	}
	if (keycode == D)
	{
		if (h->map[(int)(h->player.y + h->player.dir_x * 0.1)][(int)h->player.x] != '1')
			h->player.y += h->player.dir_x * 0.1;
		if (h->map[(int)h->player.y][(int)(h->player.x - h->player.dir_y * 0.1)] != '1')
			h->player.x -= h->player.dir_y * 0.1;
	}
	if (keycode == LEFT)
	{
		h->player.old_dir_x = h->player.dir_x;
		h->player.dir_x = h->player.dir_x * cos(-rotation) - h->player.dir_y * sin(-rotation);
		h->player.dir_y = h->player.old_dir_x * sin(-rotation) + h->player.dir_y * cos(-rotation);
		h->ray.old_plane_x = h->ray.plane_x;
		h->ray.plane_x = h->ray.plane_x * cos(-rotation) - h->ray.plane_y * sin(-rotation);
		h->ray.plane_y = h->ray.old_plane_x * sin(-rotation) + h->ray.plane_y * cos(-rotation);
	}
	if (keycode == RIGHT)
	{
		h->player.old_dir_x = h->player.dir_x;
		h->player.dir_x = h->player.dir_x * cos(rotation) - h->player.dir_y * sin(rotation);
		h->player.dir_y = h->player.old_dir_x * sin(rotation) + h->player.dir_y * cos(rotation);
		h->ray.old_plane_x = h->ray.plane_x;
		h->ray.plane_x = h->ray.plane_x * cos(rotation) - h->ray.plane_y * sin(rotation);
		h->ray.plane_y = h->ray.old_plane_x * sin(rotation) + h->ray.plane_y * cos(rotation);
	}
	if (keycode == ESC)
	{
		mlx_destroy_window(h->mnlbx.mlx, h->mnlbx.mlx_win);
		exit(0);
	}
	draw_wall(h);
	mlx_put_image_to_window(h->mnlbx.mlx, h->mnlbx.mlx_win, h->data.img, 0, 0);
	return (0);
}

int x_close()
{
	exit(0);
}