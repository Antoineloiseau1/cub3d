/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:35:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/02 10:47:20 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <math.h>

#include "../includes/cub3d.h"

double	ft_abs(double nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	ft_init_data(t_data *data, int i)
{
	data->map.camera.x = 2 * i / data->map.w - 1;
	data->map.rayDir.x = data->map.dir.x + data->map.plane.x * data->map.camera.x;
	data->map.rayDir.y = data->map.dir.y + data->map.plane.y * data->map.camera.x;
	data->map.tile_x = (int)data->map.pos.x;
	data->map.tile_y = (int)data->map.pos.y;
	if (data->map.rayDir.x == 0)
		data->map.deltaDist.x =  1 / 1e30;
	else
		data->map.deltaDist.x =  1 / ft_abs(1 / data->map.rayDir.x);
	if (data->map.rayDir.y == 0)
		data->map.deltaDist.y =  1 / 1e30;
	else
		data->map.deltaDist.y =  1 / ft_abs(1 / data->map.rayDir.y);

}

void	ft_set_step(t_data data)
{
	if (data->map.rayDir.x < 0)
	{
		data->map.step_x = -1;
		data->map.sideDist = (data->map.pos.x - data->map.tile_x) * data->map.deltaDist.x;
	}
	else
	{
		data->map.step_x = 1;
		data->map.sideDist = (data->map.pos.x + 1.0 - data->map.tile_x) * data->map.deltaDist.x;
	}
	if (data->map.rayDir.y < 0)
	{
		data->map.step_y = -1;
		data->map.sideDist = (data->map.pos.y - data->map.tile_y) * data->map.deltaDist.y;
	}
	else
	{
		data->map.step_y = 1;
		data->map.sideDist = (data->map.pos.y + 1.0 - data->map.tile_y) * data->map.deltaDist.y;
	}

}

int	ft_raycasting(t_data *data)
{
	int	i;
	int	side;
	int	hit;

	data->map.w = 0.66; ////////
	i = -1;
	while (++i < data->map.w)
	{
		ft_init_data(data, i);
		hit = 0;
		ft_set_step(data);
	}


	return (0);
}

void	ft_get_player(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
				|| map[i][j] == 'W')
			{
				data->map.pos.y = i;
				data->map.pos.x = j;
				return ;
			}
		}
	}
}

void	ft_get_dir(t_data *data)
{
	char	c;

	c = data->map.map[(int)data->map.pos.y][(int)data->map.pos.x];
	data->map.dir.y = 0;
	data->map.dir.x = 0;
	if (c == 'N')
		data->map.dir.y = 1;
	if (c == 'S')
		data->map.dir.y = -1;
	if (c == 'E')
		data->map.dir.x = 1;
	if (c == 'W')
		data->map.dir.x = -1;
}

int	ft_init_raycasting(char **map, t_data *data)
{
	ft_get_player(map, data);
	ft_get_dir(data);
	ft_raycasting(data);
	return (0);
}
