/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:56:58 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/10 07:20:02 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdlib.h>

void	free_chartab(char *tab[])
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_textures(t_textures *textures)
{
	if (textures->north.path)
		free(textures->north.path);
	if (textures->south.path)
		free(textures->south.path);
	if (textures->east.path)
		free(textures->east.path);
	if (textures->west.path)
		free(textures->west.path);
	if (textures->ceil)
		free(textures->ceil);
	if (textures->floor)
		free(textures->floor);
	free(textures);
}

void	free_data(t_data *data)
{
	if (data->file)
		free_chartab(data->file);
	if (data->map.map)
		free_chartab(data->map.map);
	if (data->textures)
		free_textures(data->textures);
	free(data);
}
