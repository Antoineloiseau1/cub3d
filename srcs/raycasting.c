/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:35:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/02 15:57:57 by anloisea         ###   ########.fr       */
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


void	ft_init_data(t_data *data, int win_strip)
{
	data->map.camera.x = 2 * win_strip / data->map.w - 1; //plan camera = (len(dir) / len(plane)
	data->map.rayDir.x = data->map.dir.x + data->map.plane.x * data->map.camera.x; //calcul du rayon (somme de dir et plane)
	data->map.rayDir.y = data->map.dir.y + data->map.plane.y * data->map.camera.y; // ||	|| 	||		||			||
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

void	set_wall_distance(t_data *data)
{
	int	hit;
	int side;
	int	perp_wall_distance;
	int	height;

	hit = 0;
	while (!hit)
	{
		if (data->map.deltaDist.x < data->map.deltaDist.y)
		{
			data->map.ray_pos.x += data->map.deltaDist.x;
			data->map.pos.x += data->map.step_x; 
			side = 0;
		}
		else
		{
			data->map.ray_pos.y += data->map.deltaDist.y;
			data->map.pos.y += data->map.step_y;			
			side = 1;
		}
		if (data->map[data->map.pos.x][data->map.pos.y] > 0)
			hit = 1;
	}
	if (side == 0)
	{
		perp_wall_distance = data->map.sideDist.x - data->map.deltaDist.x;
		wall_height = h / (data->map.ray_pos.x * perp_wall_distance);
	}
	else
	{
		perp_wall_distance = data->map.sideDist.y - data->map.deltaDist.y;
	
}

int	ft_raycasting(t_data *data)
{
	int	win_strip;
	int	side;
	int	hit;

	data->map.w = 0.66; // valeur random qui definit le plan (?!) rapport au au FOV et tout ca
	win_strip = -1;
	while (++win_strip < data->map.w)
	{
		ft_init_data(data, win_strip);
		hit = 0;
		ft_set_step(data);
		set_wall_distance(data)''
	}


	return (0);
}


//Raycasting starts at player position
void	get_player_position(char **map, t_data *data)
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

//the direction the player is going given the actual position
void	get_direction_vector(t_data *data)
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
	get_player_position(map, data);
	get_direction_vector(data);
	ft_raycasting(data);
	return (0);
}
