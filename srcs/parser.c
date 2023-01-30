/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:23:56 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/30 13:37:11 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/cub3d.h"
#include <stdio.h>

t_textures	*parse_textures(char *file[])
{
	t_textures	*textures;
	int			i;

	textures = malloc(sizeof(t_textures));
	i = 0;
	while (file[i])
	{
		if (!ft_strncmp(file[i], "NO", 2))
			textures->north = get_texture_path(file[i] + 2);
		if (!ft_strncmp(file[i], "SO", 2))
			textures->south = get_texture_path(file[i] + 2);
		if (!ft_strncmp(file[i], "WE", 2))
			textures->west = get_texture_path(file[i] + 2);
		if (!ft_strncmp(file[i], "EA", 2))
			textures->east = get_texture_path(file[i] + 2);
		i++;
	}
	return (textures);
}

char	*get_texture_path(char *line)
{
	char	*path;

	path = ft_substr(line, 0, ft_strlen(line));
	return (path);
}