/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:35:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/13 10:38:09 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

#include "../includes/cub3d.h"
#include "../includes/hook.h"
#include "../libft/libft.h" 
#include "../includes/raycasting.h"

int	ft_raycasting(t_data *data)
{
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->mlx.img = mlx_new_image(data->mlx.mlx,
			data->mlx.win_width, data->mlx.win_height);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_l, &data->mlx.endian);
	data->map.pixel = -1;
	while (++data->map.pixel < data->mlx.win_width)
		color_choice(data);
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
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

//to gain space for norm
void	set_initial_dir_data(t_data *data, double p_x, double p_y)
{
	data->map.plane.x = p_x;
	data->map.plane.y = p_y;
}

//player initial dir
void	get_initial_dir(t_data *data)
{
	char	c;

	data->map.dir.y = 0;
	data->map.dir.x = 0;
	c = data->map.map[data->map.tile_y][data->map.tile_x];
	if (c == 'N')
	{
		set_initial_dir_data(data, 0.66, 0);
		data->map.dir.y = -1;
	}
	if (c == 'S')
	{
		set_initial_dir_data(data, -0.66, 0);
		data->map.dir.y = 1;
	}
	if (c == 'E')
	{
		set_initial_dir_data(data, 0, 0.66);
		data->map.dir.x = 1;
	}
	if (c == 'W')
	{
		set_initial_dir_data(data, 0, -0.66);
		data->map.dir.x = -1;
	}
}

int	ft_init_raycasting(t_data *data)
{
	move(data);
	ft_raycasting(data);
	return (0);
}
