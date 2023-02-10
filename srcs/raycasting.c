/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:35:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/10 09:53:10 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

#include "../includes/cub3d.h"
#include "../includes/hook.h"
#include "../libft/libft.h" 

double	ft_abs(double nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

//calculs de base, pythagore et tout
void	ft_init_data(t_data *data, int pixel)
{	
	double	ratio;

	ratio = (pixel - ((double)data->mlx.win_width / 2))
		/ ((double)data->mlx.win_width / 2);
	data->map.rayDir.x = data->map.dir.x + (data->map.plane.x * ratio);
	data->map.rayDir.y = data->map.dir.y + (data->map.plane.y * ratio);
	data->map.tile_x = (int)data->map.pos.x;
	data->map.tile_y = (int)data->map.pos.y;
	data->map.deltaDist.x = sqrt(1 + (pow(data->map.rayDir.y, 2)
				/ pow(data->map.rayDir.x, 2)));
	data->map.deltaDist.y = sqrt(1 + (pow(data->map.rayDir.x, 2)
				/ pow(data->map.rayDir.y, 2)));
}

//dans quel sens on avance/regarde
void	ft_set_step(t_data *data)
{
	if (data->map.rayDir.x < 0)
	{
		data->map.step_x = -1;
		data->map.sideDist.x = (data->map.pos.x - data->map.tile_x)
			* data->map.deltaDist.x;
	}
	else
	{
		data->map.step_x = 1;
		data->map.sideDist.x = (data->map.tile_x + 1.0 - data->map.pos.x)
			* data->map.deltaDist.x;
	}
	if (data->map.rayDir.y < 0)
	{
		data->map.step_y = -1;
		data->map.sideDist.y = (data->map.pos.y - data->map.tile_y)
			* data->map.deltaDist.y;
	}
	else
	{
		data->map.step_y = 1;
		data->map.sideDist.y = (data->map.tile_y + 1.0 - data->map.pos.y)
			* data->map.deltaDist.y;
	}
}


//selon la distance mur-joueur et s'il est de face ou de profil, taille du mur
void	ft_find_wall_height(t_data *data, int side)
{
	int	lineheight;

	if (side == 0)
		data->map.perpWallDist = ft_abs((data->map.tile_x - data->map.pos.x
					+ (1 - data->map.step_x) / 2) / data->map.rayDir.x);
	else
		data->map.perpWallDist = ft_abs((data->map.tile_y - data->map.pos.y
					+ (1 - data->map.step_y) / 2) / data->map.rayDir.y);
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
	return (side);
}

void	wall_pixel_put(t_data *data, double factor)
{
	char	*mem_pix;
	float	true_i;
	int		i;
	unsigned int tex_color;

	i = data->map.draw_start;
	true_i = data->map.draw_start;
	while (i != 300)
	{
		mem_pix = data->textures->north.addr + ((i - data->map.draw_start) * data->textures->north.line_l
				+ (int)data->map.tex_x * (data->textures->north.bpp / 8));
		printf("addr %p\n", data->textures->north.addr);
		printf("pix  %p\n", mem_pix); 
		error(2, "test");
		tex_color = (unsigned int)mem_pix;
		mem_pix = data->mlx.addr + (i * data->mlx.line_l
				+ data->map.pixel * (data->mlx.bpp / 8));
		*(unsigned int *)mem_pix = tex_color;
		true_i += factor;
		i = (int)true_i;
	}
}

void	line_pixel_put(t_data *data, int start, int end, int color)
{
	char	*mem_pix;

	while (start != end)
	{
		mem_pix = data->mlx.addr + (start * data->mlx.line_l
				+ data->map.pixel * (data->mlx.bpp / 8));
		*(unsigned int *)mem_pix = color;
		start++;
	}
}

void	color_choice(t_data *data)
{
	int	side;
	float	factor;

	ft_init_data(data, data->map.pixel);
	ft_set_step(data);
	side = ft_find_wall(data);
	if (!side)
		data->map.wall_hit = data->map.pos.y + data->map.perpWallDist * data->map.rayDir.y;
	else
		data->map.wall_hit = data->map.pos.x + data->map.perpWallDist * data->map.rayDir.x;
	data->map.wall_hit -= floor(data->map.wall_hit);
	data->map.tex_x = (int)(data->map.wall_hit * (double)(300)); /////////data->texture->face.width
	if (!side && data->map.rayDir.x > 0)
		data->map.tex_x = 300 - data->map.tex_x - 1; //300 == data->texture->face.width
	else if (side && data->map.rayDir.y < 0)
		data->map.tex_x = 300 - data->map.tex_x - 1; //300 == data->texture->face.width
	factor = (double)(data->map.draw_end - data->map.draw_start) / 300.0;
	///////////////////
	if (side)
		wall_pixel_put(data, factor);
	else
		wall_pixel_put(data, factor);
	///////////////////
	line_pixel_put(data, 0, data->map.draw_start, data->textures->ceil->total);
	if (data->map.draw_end == data->mlx.win_height - 1)
		line_pixel_put(data, data->map.draw_end + 1,
			data->mlx.win_height, 0x00ccffff);
	else
		line_pixel_put(data, data->map.draw_end,
			data->mlx.win_height,data->textures->floor->total);
}

int	ft_raycasting(t_data *data)
{

	data->map.pixel = -1;
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	data->mlx.img = mlx_new_image(data->mlx.mlx,
			data->mlx.win_width, data->mlx.win_height);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_l, &data->mlx.endian);
	while (++data->map.pixel < data->mlx.win_width)
	{
		color_choice(data);
	}
//	error(1, "aled"); //stop it
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
