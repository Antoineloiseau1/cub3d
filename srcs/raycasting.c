/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:35:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/06 09:29:38 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <math.h>
#include <mlx.h> 
#include <unistd.h>

#include "../includes/cub3d.h"

double	ft_abs(double nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

//calculs de base, pythagore et tout
void	ft_init_data(t_data *data, int pixel)
{	
	double ratio;

	ratio = (pixel - ((double)data->mlx.win_width / 2)) / ((double)data->mlx.win_width / 2);
	data->map.rayDir.x = data->map.dir.x + (data->map.plane.x * ratio);
	data->map.rayDir.y = data->map.dir.y + (data->map.plane.y * ratio);
	data->map.tile_x = (int)data->map.pos.x;
	data->map.tile_y = (int)data->map.pos.y;
	data->map.deltaDist.x = sqrt(1 + (pow(data->map.rayDir.y, 2) / pow(data->map.rayDir.x, 2)));
	data->map.deltaDist.y = sqrt(1 + (pow(data->map.rayDir.x, 2) / pow(data->map.rayDir.y, 2)));
	// if (data->map.rayDir.x == 0.0)
	// 	data->map.deltaDist.x = 1e30;
	// else
	// 	data->map.deltaDist.x = sqrt(1 + ((data->map.rayDir.y * data->map.rayDir.y) / (data->map.rayDir.x * data->map.rayDir.x)));
	// if (data->map.rayDir.y == 0.0)
	// 	data->map.deltaDist.y = 1e30;
	// else
	// 	data->map.deltaDist.y = sqrt(1 + ((data->map.rayDir.x * data->map.rayDir.x) / (data->map.rayDir.y * data->map.rayDir.y)));
}
//dans quel sens on avance/regarde
void	ft_set_step(t_data *data)
{
	if (data->map.rayDir.x < 0)
	{
		data->map.step_x = -1;
		data->map.sideDist.x = (data->map.pos.x - data->map.tile_x) * data->map.deltaDist.x;
	}
	else
	{
		data->map.step_x = 1;
		data->map.sideDist.x = (data->map.tile_x + 1.0 - data->map.pos.x) * data->map.deltaDist.x;
	}
	if (data->map.rayDir.y < 0)
	{
		data->map.step_y = -1;
		data->map.sideDist.y = (data->map.pos.y - data->map.tile_y) * data->map.deltaDist.y;
	}
	else
	{
		data->map.step_y = 1;
		data->map.sideDist.y = (data->map.tile_y + 1.0 - data->map.pos.y) * data->map.deltaDist.y;
	}

}

void	line_pixel_put(t_data *data, int line_to_draw, int start, int end, int color)
{
	while (++start != end)
	{
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, line_to_draw, start, color);
	}
}

//selon la distance mur-joueur et s'il est de face ou de profil, taille du mur
void	ft_find_wall_height(t_data *data, int side)
{
	int	lineheight;

	if (side == 0)
		data->map.perpWallDist = data->map.sideDist.x - data->map.deltaDist.x;
	else
		data->map.perpWallDist = data->map.sideDist.y - data->map.deltaDist.y;
	lineheight = (int)((double)(data->mlx.win_height / data->map.perpWallDist));
	data->map.draw_start = (-lineheight / 2) + (data->mlx.win_height / 2);
	if (data->map.draw_start < 0)
		data->map.draw_start = 0;
	data->map.draw_end = (lineheight / 2) + (data->mlx.win_height / 2);
	if (data->map.draw_end >= data->mlx.win_height)
		data->map.draw_end = data->mlx.win_height - 1;

}
//a combien de '"cases"' est le mur
int	ft_find_wall(t_data *data)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (data->map.sideDist.x < data->map.sideDist.y)
		{
			data->map.sideDist.x += data->map.deltaDist.x;
			data->map.tile_x += data->map.step_x;
			side = 0;
		}
		else
		{
			data->map.sideDist.y += data->map.deltaDist.y;
			data->map.tile_y += data->map.step_y;
			side = 1;
		}
		if (data->map.map[data->map.tile_y][data->map.tile_x] == '1')
			hit = 1;
	}
	ft_find_wall_height(data, side);
	data->map.tile_x = (int)data->map.pos.x; /////debug
	data->map.tile_y = (int)data->map.pos.y;
	return (side);
}

int	ft_raycasting(t_data *data)
{
	int	pixel;

	pixel = -1;
	while (++pixel < data->mlx.win_width)
	{
		ft_init_data(data, pixel);
		ft_set_step(data);
		int side = ft_find_wall(data);
		if (side)
			line_pixel_put(data, pixel, data->map.draw_start - 1, data->map.draw_end, 100);
		else
			line_pixel_put(data, pixel, data->map.draw_start - 1, data->map.draw_end, 150);
//		line_pixel_put(data, pixel, 0, data->map.draw_start, 789687465);
//		line_pixel_put(data, pixel, data->map.draw_end, data->mlx.win_height, 12345645);
	}


	return (0);
}


//player position on the map;
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
				data->map.pos.y = i + 0.5;
				data->map.pos.x = j + 0.5;
				data->map.tile_y = floor(data->map.pos.y);
				data->map.tile_x = floor(data->map.pos.x);
				return ;
			}
		}
	}
}

//player initial dir
void	get_initial_dir(t_data *data)
{
	char	c;

	c = data->map.map[data->map.tile_y][data->map.tile_x];
	data->map.dir.y = 0;
	data->map.dir.x = 0;
	if (c == 'N')
	{
		data->map.plane.x = 0.66;
		data->map.plane.y = 0;
		data->map.dir.y = -1;
	}
	if (c == 'S')
	{
		data->map.plane.x = -0.66;
		data->map.plane.y = 0;
		data->map.dir.y = 1;
	}
	if (c == 'E')
	{
		data->map.plane.x = 0;
		data->map.plane.y = 0.66;
		data->map.dir.x = 1;
	}
	if (c == 'W')
	{
		data->map.plane.x = 0;
		data->map.plane.y = -0.66;
		data->map.dir.x = -1;
	}
}

int	ft_init_raycasting(t_data *data)
{
	puts("coucou");
	ft_raycasting(data);
	return (0);
}
