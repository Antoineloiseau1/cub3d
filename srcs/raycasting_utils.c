/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:32:33 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/13 10:39:48 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/raycasting.h"
#include <math.h>

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
	data->map.ray_dir.x = data->map.dir.x + (data->map.plane.x * ratio);
	data->map.ray_dir.y = data->map.dir.y + (data->map.plane.y * ratio);
	data->map.tile_x = (int)data->map.pos.x;
	data->map.tile_y = (int)data->map.pos.y;
	data->map.delta_dist.x = sqrt(1 + (pow(data->map.ray_dir.y, 2)
				/ pow(data->map.ray_dir.x, 2)));
	data->map.delta_dist.y = sqrt(1 + (pow(data->map.ray_dir.x, 2)
				/ pow(data->map.ray_dir.y, 2)));
}

//dans quel sens on avance/regarde
void	ft_set_step(t_data *data)
{
	if (data->map.ray_dir.x < 0)
	{
		data->map.step_x = -1;
		data->map.side_dist.x = (data->map.pos.x - data->map.tile_x)
			* data->map.delta_dist.x;
	}
	else
	{
		data->map.step_x = 1;
		data->map.side_dist.x = (data->map.tile_x + 1.0 - data->map.pos.x)
			* data->map.delta_dist.x;
	}
	if (data->map.ray_dir.y < 0)
	{
		data->map.step_y = -1;
		data->map.side_dist.y = (data->map.pos.y - data->map.tile_y)
			* data->map.delta_dist.y;
	}
	else
	{
		data->map.step_y = 1;
		data->map.side_dist.y = (data->map.tile_y + 1.0 - data->map.pos.y)
			* data->map.delta_dist.y;
	}
}

void	wall_pixel_put(t_data *data, float factor, t_image current)
{
	char			*mem_pix;
	int				i;
	float			true_i;
	unsigned int	tex_color;

	i = 0;
	true_i = 0;
	while (data->map.draw_start != data->map.draw_end && i < current.width)
	{
		while (data->map.draw_end >= data->mlx.win_height)
		{
			data->map.draw_end--;
			true_i += factor;
		}
		mem_pix = current.addr + ((i) * current.line_l
				+ data->map.tex_x * (current.bpp / 8));
		tex_color = *(unsigned int *)mem_pix;
		mem_pix = data->mlx.addr + (data->map.draw_start
				* data->mlx.line_l + data->map.pixel * (data->mlx.bpp / 8));
		*(unsigned int *)mem_pix = tex_color;
		data->map.draw_start++;
		true_i += factor;
		i = (floor)(true_i);
	}
}

void	line_pixel_put(t_data *data, int start, int end, int color)
{
	char	*mem_pix;

	while (start != end && start < data->mlx.win_height)
	{
		mem_pix = data->mlx.addr + (start * data->mlx.line_l
				+ data->map.pixel * (data->mlx.bpp / 8));
		*(unsigned int *)mem_pix = color;
		start++;
	}
}
