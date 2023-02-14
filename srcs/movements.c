/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:10:31 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/14 16:05:36 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/hook.h"

void	move_forward(t_data *data)
{
	char	c;
	char	d;

	c = data->map.map[(int)(data->map.pos.y)]
	[(int)(data->map.pos.x - 0.04 + data->map.dir.x * FRONT_SPEED)];
	d = data->map.map[(int)(data->map.pos.y)]
	[(int)(data->map.pos.x + 0.04 + data->map.dir.x * FRONT_SPEED)];
	if (c != '1' && d != '1')
		data->map.pos.x += data->map.dir.x * FRONT_SPEED;
	c = data->map.map[(int)(data->map.pos.y - 0.04
			+ data->map.dir.y * FRONT_SPEED)][(int)data->map.pos.x];
	d = data->map.map[(int)(data->map.pos.y + 0.04
			+ data->map.dir.y * FRONT_SPEED)][(int)data->map.pos.x];
	if (c != '1' && d != '1')
		data->map.pos.y += data->map.dir.y * FRONT_SPEED;
}

void	move_backward(t_data *data)
{
	char	c;
	char	d;

	c = data->map.map[(int)data->map.pos.y]
	[(int)(data->map.pos.x + 0.04 - data->map.dir.x * BACK_SPEED)];
	d = data->map.map[(int)data->map.pos.y]
	[(int)(data->map.pos.x - 0.04 - data->map.dir.x * BACK_SPEED)];
	if (c != '1' && d != '1')
		data->map.pos.x -= data->map.dir.x * BACK_SPEED;
	c = data->map.map[(int)(data->map.pos.y + 0.04
			- data->map.dir.y * BACK_SPEED)][(int)data->map.pos.x];
	d = data->map.map[(int)(data->map.pos.y - 0.04
			- data->map.dir.y * BACK_SPEED)][(int)data->map.pos.x];
	if (c != '1' && d != '1')
		data->map.pos.y -= data->map.dir.y * BACK_SPEED;
}

void	move_left(t_data *data)
{
	char	c;
	char	d;

	c = data->map.map[(int)data->map.pos.y]
	[(int)(data->map.pos.x + 0.04 - data->map.plane.x * TRANS_SPEED)];
	d = data->map.map[(int)data->map.pos.y]
	[(int)(data->map.pos.x - 0.04 - data->map.plane.x * TRANS_SPEED)];
	if (c != '1' && d != '1')
		data->map.pos.x -= data->map.plane.x * TRANS_SPEED;
	c = data->map.map[(int)(data->map.pos.y
			+ 0.04 - data->map.plane.y * TRANS_SPEED)][(int)data->map.pos.x];
	d = data->map.map[(int)(data->map.pos.y
			- 0.04 - data->map.plane.y * TRANS_SPEED)][(int)data->map.pos.x];
	if (c != '1' && d != '1')
		data->map.pos.y -= data->map.plane.y * TRANS_SPEED;
}

void	move_right(t_data *data)
{
	char	c;
	char	d;

	c = data->map.map[(int)data->map.pos.y]
	[(int)(data->map.pos.x + 0.04 + data->map.plane.x * TRANS_SPEED)];
	d = data->map.map[(int)data->map.pos.y]
	[(int)(data->map.pos.x - 0.04 + data->map.plane.x * TRANS_SPEED)];
	if (c != '1' && d != '1')
		data->map.pos.x += data->map.plane.x * TRANS_SPEED;
	c = data->map.map[(int)(data->map.pos.y
			+ 0.04 + data->map.plane.y * TRANS_SPEED)][(int)data->map.pos.x];
	d = data->map.map[(int)(data->map.pos.y
			- 0.04 + data->map.plane.y * TRANS_SPEED)][(int)data->map.pos.x];
	if (c != '1' && d != '1')
		data->map.pos.y += data->map.plane.y * TRANS_SPEED;
}

int	move(t_data *data)
{
	if (data->mlx.up)
		move_forward(data);
	if (data->mlx.down)
		move_backward(data);
	if (data->mlx.left)
		move_left(data);
	if (data->mlx.right)
		move_right(data);
	if (data->mlx.r_left)
		rotate_left(data);
	if (data->mlx.r_right)
		rotate_right(data);
	return (0);
}
