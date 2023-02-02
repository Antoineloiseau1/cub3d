/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:38:03 by antoine           #+#    #+#             */
/*   Updated: 2023/02/01 12:07:21 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdlib.h>

void	check_file(t_data *data)
{
	if (data->file == NULL)
	{
		free(data);
		error(-1, "file is empty");
	}
}

void	check_if_textures_parsed(t_data *data)
{
	if (check_textures(data->textures))
	{
		data->map.map = NULL;
		free_data(data);
		error(1, "textures undefined");
	}
}
