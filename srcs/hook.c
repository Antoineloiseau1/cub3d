/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:23:05 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/06 08:22:02 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h> 

#include "../includes/raycasting.h" 
#include "../includes/cub3d.h"

void	front_walk(t_data *data)
{
	data->map.pos.x += data->map.dir.x * 0.5;
	data->map.pos.y += data->map.dir.y * 0.5;
//	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	ft_raycasting(data);
}

void	ft_movement(int key, t_data *data)
{
	if (key == 13)
		front_walk(data);
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
	if ((key <= 2 && key >= 0) || key == 13)
		ft_movement(key, data);
	return (0);
}

void	hooking(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, ft_close, 0);
	mlx_key_hook(data->mlx.win, key_handler, data);
}
