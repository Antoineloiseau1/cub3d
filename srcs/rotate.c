/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:14:59 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/13 10:17:40 by anloisea         ###   ########.fr       */
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
