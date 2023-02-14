/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:38:03 by antoine           #+#    #+#             */
/*   Updated: 2023/02/14 09:39:36 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include <stdlib.h>

void	check_check(int *check, t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (check[i] != 1)
		{
			free(check);
			free(data->file);
			free(data);
			error(2, "duplicate or undefined textures");
		}
		i++;
	}
}

void	count_textures(char *line, int *check)
{
	int	j;

	j = 0;
	while (ft_isspace(line[j]))
		j++;
	if (!ft_strncmp(line + j, "NO ", 3))
		check[0]++;
	if (!ft_strncmp(line + j, "SO ", 3))
		check[1]++;
	if (!ft_strncmp(line + j, "EA ", 3))
		check[2]++;
	if (!ft_strncmp(line + j, "WE ", 3))
		check[3]++;
	if (!ft_strncmp(line + j, "C ", 2))
		check[4]++;
	if (!ft_strncmp(line + j, "F ", 2))
		check[5]++;
}

void	check_file(t_data *data)
{
	int	*check;
	int	i;

	i = -1;
	if (data->file == NULL)
	{
		free(data);
		error(-1, "file is empty");
	}
	check = ft_calloc(6, sizeof(int));
	while (data->file[++i])
		count_textures(data->file[i], check);
	check_check(check, data);
	free(check);
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
