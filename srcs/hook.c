/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:23:05 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/06 12:12:49 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>

#include "../includes/raycasting.h" 
#include "../includes/cub3d.h"

void	move_forward(t_data *data)
{
	data->map.pos.x += data->map.dir.x * 0.23;
	data->map.pos.y += data->map.dir.y * 0.23;
}

void	move_backward(t_data *data)
{
	data->map.pos.x -= data->map.dir.x * 0.15;
	data->map.pos.y -= data->map.dir.y * 0.15;
}

void	move_left(t_data *data)
{
	data->map.pos.x -= data->map.plane.x * 0.07;
	data->map.pos.y -= data->map.plane.y * 0.07;
}

void	move_right(t_data *data)
{
	data->map.pos.x += data->map.plane.x * 0.07;
	data->map.pos.y += data->map.plane.y * 0.07;
}

void	rotate_right(t_data *data)
{
	double save;
	
	save = data->map.dir.x;
	data->map.dir.x = (cos(0.23) * data->map.dir.x - sin(0.23) * data->map.dir.y);
	data->map.dir.y = (sin(0.23) * save + cos(0.23) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(0.23) * data->map.plane.x - sin(0.23) * data->map.plane.y);
	data->map.plane.y = (sin(0.23) * save + cos(0.23) * data->map.plane.y);
}

void	rotate_left(t_data *data)
{
	double save;
	
	save = data->map.dir.x;
	data->map.dir.x = (cos(-0.23) * data->map.dir.x - sin(-0.23) * data->map.dir.y);
	data->map.dir.y = (sin(-0.23) * save + cos(-0.23) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(-0.23) * data->map.plane.x - sin(-0.23) * data->map.plane.y);
	data->map.plane.y = (sin(-0.23) * save + cos(-0.23) * data->map.plane.y);
}

void	ft_movement(int key, t_data *data)
{
	if (key == 13)
		move_forward(data);
	if (key == 1)
		move_backward(data);
	if (key == 0)
		move_left(data);
	if (key == 2)
		move_right(data);
	if (key == 123)
		rotate_left(data);
	if (key == 124)
		rotate_right(data);
	printf("------------\n");
	printf("pos.x = %f\n", data->map.pos.x);
	printf("pos.y = %f\n", data->map.pos.y);
	printf("------------\n");
	printf("dir.x = %f\n", data->map.dir.x);
	printf("dir.y = %f\n", data->map.dir.y);
	printf("------------\n");
	printf("plane.x = %f\n", data->map.plane.x);
	printf("plane.y = %f\n", data->map.plane.y);
	printf("------------\n");
}


int	ft_close(void)
{
	exit(0);
}

int	key_handler(int key, t_data *data)
{
	printf("key %d\n",key); 
	if (key == 53)
		exit(0);
	if ((key <= 2 && key >= 0) || key == 13 || key == 123 || key == 124)
		ft_movement(key, data);
	return (0);
}

void	hooking(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, ft_close, 0);
	mlx_hook(data->mlx.win, 2, (1L<<15), key_handler, data);
	mlx_loop_hook(data->mlx.mlx, ft_raycasting, data);
}
