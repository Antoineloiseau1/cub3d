/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:23:05 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/13 14:37:14 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#include "../includes/raycasting.h" 
#include "../includes/cub3d.h"
#include "../includes/hook.h"

int	ft_close(void)
{
	exit(0);
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
	if (key == L_ARROW)
		data->mlx.r_left = true;
	if (key == R_ARROW)
		data->mlx.r_right = true;
	if (key == ESCAPE)
		ft_close();
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
	if (key == L_ARROW)
		data->mlx.r_left = false;
	if (key == R_ARROW)
		data->mlx.r_right = false;
	return (key);
}

//pointer handle maybe
int	mouse_handler(int x, int y, t_data *data)
{
	mlx_mouse_get_pos(data->mlx.win, &data->mlx.old_x, &y);
	if (x < data->mlx.old_x)
		rotate_right(data);
	if (x > data->mlx.old_x)
		rotate_left(data);
	if (x >= 1279)
		mlx_mouse_move(data->mlx.win, 900, 540);
	else if (x <= 0)
		mlx_mouse_move(data->mlx.win, 900, 540);
	else
		data->mlx.old_x = x;
	return (x);
}

void	hooking(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, ft_close, 0);
	mlx_hook(data->mlx.win, 2, 0, press, data);
	mlx_loop_hook(data->mlx.mlx, ft_init_raycasting, data);
	mlx_hook(data->mlx.win, 3, 0, unpress, data);
	mlx_hook(data->mlx.win, 6, (1L << 15), mouse_handler, data);
}
