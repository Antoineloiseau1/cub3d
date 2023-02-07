/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:23:05 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/07 10:28:46 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "../includes/raycasting.h" 
#include "../includes/cub3d.h"

#define ROTATE_SPEED 0.04
#define FRONT_SPEED 0.25
#define BACK_SPEED 0.18
#define TRANSLATE_SPEED 0.15
#define ESCAPE 65307
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define L_ARROW 65361
#define R_ARROW 65363

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

int	press(int key, t_data *data)
{
	if (key == UP)
		data->mlx.up = true;
	if (key == DOWN)
		data->mlx.down = true;
	if (key == LEFT)
		data->mlx.left = true;
	if (key == RIGHT)
		data->mlx.right = true;
	printf("%d\n", data->mlx.up);
	// if (key == L_ARROW)
	// 	rotate_left(data);
	// if (key == R_ARROW)
	// 	rotate_right(data);
	return (key);
}

int	unpress(int key, t_data *data)
{
	if (key == UP)
		data->mlx.up = false;
	if (key == DOWN)
		data->mlx.down = false;
	if (key == LEFT)
		data->mlx.left = false;
	if (key == RIGHT)
		data->mlx.right = false;
	return (key);
}

int	ft_close(void)
{
	exit(0);
}

int	move(int key, t_data *data)
{
	if (key == UP)
		move_forward(data);
	if (key == DOWN)
		move_backward(data);
	if (key == LEFT)
		move_left(data);
	if (key == RIGHT)
		move_right(data);
	if (key == L_ARROW)
		rotate_left(data);
	if (key == R_ARROW)
		rotate_right(data);
	return (key);
}


int	key_handler(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == ESCAPE)
		exit(0);
	move(key, data);
	return (0);
}

int	mouse_handler(int x, int y, t_data *data)
{
	(void)y;
	printf("x: %d y: %d\n", x, y);
	if (x == 1)
	 return (data->mlx.old_x);
	if (x > data->mlx.old_x)
		rotate_right(data);
	if (x < data->mlx.old_x)
		rotate_left(data);
	if (x >= 1275)
		data->mlx.old_x = 0;
	else if (x <= 5)
		data->mlx.old_x = 1279;
	else
		data->mlx.old_x = x;
	return (x);
}

void	hooking(t_data *data)
{
	mlx_key_hook(data->mlx.win,key_handler, data);
	// if (data->mlx.up)
	// 	mlx_key_hook(data->mlx.mlx, move, data);
	// //mlx_hook(data->mlx.win, 3, 0, unpress, data);
//	mlx_hook(data->mlx.win, 6, (1L<<15), mouse_handler, data);
	mlx_hook(data->mlx.win, 17, 0, ft_close, 0);
	mlx_loop_hook(data->mlx.mlx, ft_raycasting, data);
	
}