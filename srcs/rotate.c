/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:14:59 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/14 13:44:53 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	rotate_right(t_data *data)
{
	double	save;

	save = data->map.dir.x;
	data->map.dir.x = (cos(ROTATE_SPEED) * data->map.dir.x
			- sin(ROTATE_SPEED) * data->map.dir.y);
	data->map.dir.y = (sin(ROTATE_SPEED) * save
			+ cos(ROTATE_SPEED) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(ROTATE_SPEED) * data->map.plane.x
			- sin(ROTATE_SPEED) * data->map.plane.y);
	data->map.plane.y = (sin(ROTATE_SPEED) * save
			+ cos(ROTATE_SPEED) * data->map.plane.y);
}

void	rotate_left(t_data *data)
{
	double	save;

	save = data->map.dir.x;
	data->map.dir.x = (cos(-ROTATE_SPEED) * data->map.dir.x
			- sin(-ROTATE_SPEED) * data->map.dir.y);
	data->map.dir.y = (sin(-ROTATE_SPEED) * save
			+ cos(-ROTATE_SPEED) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(-ROTATE_SPEED) * data->map.plane.x
			- sin(-ROTATE_SPEED) * data->map.plane.y);
	data->map.plane.y = (sin(-ROTATE_SPEED) * save
			+ cos(-ROTATE_SPEED) * data->map.plane.y);
}

void	mouse_rotate_left(t_data *data)
{
	double	save;

	save = data->map.dir.x;
	data->map.dir.x = (cos(-M_ROTATE_SPEED) * data->map.dir.x
			- sin(-M_ROTATE_SPEED) * data->map.dir.y);
	data->map.dir.y = (sin(-M_ROTATE_SPEED) * save
			+ cos(-M_ROTATE_SPEED) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(-M_ROTATE_SPEED) * data->map.plane.x
			- sin(-M_ROTATE_SPEED) * data->map.plane.y);
	data->map.plane.y = (sin(-M_ROTATE_SPEED) * save
			+ cos(-M_ROTATE_SPEED) * data->map.plane.y);
}

void	mouse_rotate_right(t_data *data)
{
	double	save;

	save = data->map.dir.x;
	data->map.dir.x = (cos(M_ROTATE_SPEED) * data->map.dir.x
			- sin(M_ROTATE_SPEED) * data->map.dir.y);
	data->map.dir.y = (sin(M_ROTATE_SPEED) * save
			+ cos(M_ROTATE_SPEED) * data->map.dir.y);
	save = data->map.plane.x;
	data->map.plane.x = (cos(M_ROTATE_SPEED) * data->map.plane.x
			- sin(M_ROTATE_SPEED) * data->map.plane.y);
	data->map.plane.y = (sin(M_ROTATE_SPEED) * save
			+ cos(M_ROTATE_SPEED) * data->map.plane.y);
}
