/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:37:53 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/13 10:41:06 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/raycasting.h"
#include <math.h>

//selon la distance mur-joueur et s'il est de face ou de profil, taille du mur
void	ft_find_wall_height(t_data *data, int side)
{
	int	lineheight;

	if (side == 0)
		data->map.perp_wall_dist = ft_abs((data->map.tile_x - data->map.pos.x
					+ (1 - data->map.step_x) / 2) / data->map.ray_dir.x);
	else
		data->map.perp_wall_dist = ft_abs((data->map.tile_y - data->map.pos.y
					+ (1 - data->map.step_y) / 2) / data->map.ray_dir.y);
	lineheight = (int)((double)(data->mlx.win_height
				/ data->map.perp_wall_dist));
	data->map.draw_start = (-lineheight / 2) + (data->mlx.win_height / 2);
	if (data->map.draw_start < 0)
		data->map.draw_start = 0;
	data->map.draw_end = (lineheight / 2) + (data->mlx.win_height / 2);
}

//a combien de '"cases"' est le mur
int	ft_find_wall(t_data *data)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (data->map.side_dist.x < data->map.side_dist.y)
		{
			data->map.side_dist.x += data->map.delta_dist.x;
			data->map.tile_x += data->map.step_x;
			side = 0;
		}
		else
		{
			data->map.side_dist.y += data->map.delta_dist.y;
			data->map.tile_y += data->map.step_y;
			side = 1;
		}
		if (data->map.map[data->map.tile_y][data->map.tile_x] == '1')
			hit = 1;
	}
	ft_find_wall_height(data, side);
	return (side);
}

t_image	choose_image(t_data *data, int side)
{
	if (data->map.ray_dir.y <= 0 && side)
		return (data->textures->north);
	if (data->map.ray_dir.y > 0 && side)
		return (data->textures->south);
	if (data->map.ray_dir.x > 0 && !side)
		return (data->textures->east);
	if (data->map.ray_dir.x <= 0 && !side)
		return (data->textures->west);
	return (data->textures->north);
}

void	define_impact_point(t_data *data, int side, t_image *current)
{
	if (!side)
		data->map.wall_hit = data->map.pos.y + data->map.perp_wall_dist
			* data->map.ray_dir.y;
	else
		data->map.wall_hit = data->map.pos.x + data->map.perp_wall_dist
			* data->map.ray_dir.x;
	data->map.wall_hit -= floor(data->map.wall_hit);
	data->map.tex_x = (int)((data->map.wall_hit * (double)current->width));
	if (!side && data->map.ray_dir.x < 0)
		data->map.tex_x = current->width - data->map.tex_x - 1;
	else if (side && data->map.ray_dir.y > 0)
		data->map.tex_x = current->width - data->map.tex_x - 1;
}

void	color_choice(t_data *data)
{
	double	factor;
	int		side;
	t_image	current;

	ft_init_data(data, data->map.pixel);
	ft_set_step(data);
	side = ft_find_wall(data);
	current = choose_image(data, side);
	define_impact_point(data, side, &current);
	factor = 1.0 * current.height / (int)((double)(data->mlx.win_height
				/ data->map.perp_wall_dist));
	line_pixel_put(data, 0, data->map.draw_start, data->textures->ceil->total);
	if (data->map.draw_end == data->mlx.win_height - 1)
		line_pixel_put(data, data->map.draw_end + 1,
			data->mlx.win_height - 1, data->textures->floor->total);
	else
		line_pixel_put(data, data->map.draw_end,
			data->mlx.win_height - 1, data->textures->floor->total);
	wall_pixel_put(data, factor, current);
}
