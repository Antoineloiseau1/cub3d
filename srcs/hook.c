/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:23:05 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/06 12:19:16 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>

#include "../includes/raycasting.h" 
#include "../includes/cub3d.h"

# define ROTATE_SPEED 0.1
# define FRONT_SPEED 0.25
# define BACK_SPEED 0.18
# define TRANSLATE_SPEED 0.15

void	move_forward(t_data *data)
{
	data->map.pos.x += data->map.dir.x * FRONT_SPEED;
	data->map.pos.y += data->map.dir.y * FRONT_SPEED;
}

void	move_backward(t_data *data)
{
	data->map.pos.x -= data->map.dir.x * BACK_SPEED;
	data->map.pos.y -= data->map.dir.y * BACK_SPEED;
}

void	move_left(t_data *data)
{
	data->map.pos.x -= data->map.plane.x * TRANSLATE_SPEED;
	data->map.pos.y -= data->map.plane.y * TRANSLATE_SPEED;
}

void	move_right(t_data *data)
{
	data->map.pos.x += data->map.plane.x * TRANSLATE_SPEED;
	data->map.pos.y += data->map.plane.y * TRANSLATE_SPEED;
}

void	rotate_right(t_data *data)
{
	double save;
	
	save = data->map.dir.x;
	data->map.dir.x = (cos(ROTATE_SPEED) * data->map.dir.x - sin(ROTATE_SPEED) * data->map.dir.y);
	data->map.dir.y = (sin(ROTATE_SPEED) * save + cos(ROTATE_SPEED) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(ROTATE_SPEED) * data->map.plane.x - sin(ROTATE_SPEED) * data->map.plane.y);
	data->map.plane.y = (sin(ROTATE_SPEED) * save + cos(ROTATE_SPEED) * data->map.plane.y);
}

void	rotate_left(t_data *data)
{
	double save;
	
	save = data->map.dir.x;
	data->map.dir.x = (cos(-ROTATE_SPEED) * data->map.dir.x - sin(-ROTATE_SPEED) * data->map.dir.y);
	data->map.dir.y = (sin(-ROTATE_SPEED) * save + cos(-ROTATE_SPEED) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(-ROTATE_SPEED) * data->map.plane.x - sin(-ROTATE_SPEED) * data->map.plane.y);
	data->map.plane.y = (sin(-ROTATE_SPEED) * save + cos(-ROTATE_SPEED) * data->map.plane.y);
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
