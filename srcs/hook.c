/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:23:05 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/06 10:20:48 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h> 
#include <stdio.h> 

#include "../includes/raycasting.h" 
#include "../includes/cub3d.h"

void	front_walk(t_data *data)
{
	data->map.pos.x += data->map.dir.x * 0.07;
	data->map.pos.y += data->map.dir.y * 0.07;
}

void	back_walk(t_data *data)
{
	data->map.pos.x -= data->map.dir.x * 0.07;
	data->map.pos.y -= data->map.dir.y * 0.07;
}


void	ft_movement(int key, t_data *data)
{
	if (key == 13)
		front_walk(data);
	if (key == 1)
		back_walk(data);
	ft_raycasting(data);
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
