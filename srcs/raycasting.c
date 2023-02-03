/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <mmidon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:35:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/03 09:55:38 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <math.h>
#include <mlx.h> 

#include "../includes/cub3d.h"

double	ft_abs(double nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

//calculs de base, pythagore et tout
void	ft_init_data(t_data *data, int i)
{
	data->map.plane.x = 0; 
	data->map.plane.y = 0.66; ///fov correct

	data->map.camera.x = (2 * i) / (data->mlx.win_width - 1);
	data->map.rayDir.x = data->map.dir.x + data->map.plane.x * data->map.camera.x;
	data->map.rayDir.y = data->map.dir.y + data->map.plane.y * data->map.camera.x;
	data->map.tile_x = (int)data->map.pos.x;
	data->map.tile_y = (int)data->map.pos.y;
	if (data->map.rayDir.x == 0)
		data->map.deltaDist.x =  1e30;
	else
		data->map.deltaDist.x =  1 / ft_abs(1 / data->map.rayDir.x);
	if (data->map.rayDir.y == 0)
		data->map.deltaDist.y =  1e30;
	else
		data->map.deltaDist.y =  1 / ft_abs(1 / data->map.rayDir.y);

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
		data->map.sideDist.x = (data->map.pos.x + 1.0 - data->map.tile_x) * data->map.deltaDist.x;
	}
	if (data->map.rayDir.y < 0)
	{
		data->map.step_y = -1;
		data->map.sideDist.y = (data->map.pos.y - data->map.tile_y) * data->map.deltaDist.y;
	}
	else
	{
		data->map.step_y = 1;
		data->map.sideDist.y = (data->map.pos.y + 1.0 - data->map.tile_y) * data->map.deltaDist.y;
	}

}

void	line_pixel_put(t_data *data, int line_to_draw, int start, int end, int color)
{
	printf("start %d end %d\n", start, end);
	(void)color;
	while (start != end)
	{
		
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, line_to_draw, start, color);
		start++;
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
	lineheight = (int)(data->mlx.win_height / data->map.perpWallDist);
	data->map.draw_start = -lineheight / 2 + data->mlx.win_height / 2;
	if (data->map.draw_start < 0)
		data->map.draw_start = 0;
	data->map.draw_end = lineheight / 2 + data->mlx.win_height / 2;
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
		printf("%f	%f", data->map.pos.x ,data->map.pos.y);
		if (data->map.sideDist.x < data->map.sideDist.y)
		{
			data->map.sideDist.x += data->map.deltaDist.x;
			data->map.pos.x += data->map.step_x;
			side = 0;
		}
		else
		{
			data->map.sideDist.y += data->map.deltaDist.y;
			data->map.pos.y += data->map.step_y;
			side = 1;
		}
		if (data->map.map[(int)data->map.pos.y][(int)data->map.pos.x] == '1')
			hit = 1;
	}
	ft_find_wall_height(data, side);
	data->map.pos.x = 2; /////debug
	data->map.pos.y = 1;
	return (side);
}

int	ft_raycasting(t_data *data)
{
	int	i;

	data->mlx.win_width = 400; //////// random value, win width;
	data->mlx.win_height = 400;
	i = -1;
	while (++i < data->mlx.win_width)
	{
		ft_init_data(data, i);
		ft_set_step(data);
		int side = ft_find_wall(data);
		if (side)
			line_pixel_put(data, i, data->map.draw_start, data->map.draw_end, 100);
		else
			line_pixel_put(data, i, data->map.draw_start, data->map.draw_end, 123456664);
	}


	return (0);
}


//player position on the map;
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

//player initial dir
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
