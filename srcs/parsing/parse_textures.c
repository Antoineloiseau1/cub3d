/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:23:56 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/14 09:17:02 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"
#include <stdio.h>

char	*search_texture_id(char *line, const char *id)
{
	int		i;
	char	**tmp;
	char	*path;

	i = 0;
	tmp = NULL;
	path = NULL;
	if (!line)
		return (NULL);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!ft_strncmp(line + i, id, ft_strlen(id)))
	{
		tmp = ft_split(line, ' ');
		if (tab_len(tmp) != 2)
			return (NULL);
		path = ft_strdup(tmp[1]);
		free_chartab(tmp);
	}
	return (path);
}

t_color	*get_rgb_values(char *raw_values)
{
	t_color	*colors;
	char	**values;

	values = split_and_trim_raw_values(raw_values);
	if (!values)
		return (NULL);
	colors = malloc(sizeof(t_color));
	if (!colors)
		return (NULL);
	colors->red = ft_atoi(values[0]);
	colors->green = ft_atoi(values[1]);
	colors->blue = ft_atoi(values[2]);
	free_chartab(values);
	if (colors->red < 0 || colors->red > 255)
		return (NULL);
	if (colors->green < 0 || colors->green > 255)
		return (NULL);
	if (colors->blue < 0 || colors->blue > 255)
		return (NULL);
	return (colors);
}

t_color	*search_color_id(char *line, char id)
{
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == id)
	{
		i++;
		while (line[i] && ft_isspace(line[i]))
			i++;
		return (get_rgb_values(line + i));
	}
	return (NULL);
}

void	parse_colors(char *file[], t_textures *textures)
{
	int		i;

	textures->ceil = NULL;
	textures->floor = NULL;
	i = 0;
	while (file[i])
	{
		if (!file[i][0])
			i++;
		if (textures->ceil == NULL)
			textures->ceil = search_color_id(file[i], 'C');
		if (textures->floor == NULL)
			textures->floor = search_color_id(file[i], 'F');
		i++;
	}
}

t_textures	*parse_textures(char *file[])
{
	t_textures	*textures;
	int			i;

	textures = malloc(sizeof(t_textures));
	i = 0;
	textures->north.path = NULL;
	textures->south.path = NULL;
	textures->east.path = NULL;
	textures->west.path = NULL;
	while (file[i])
	{
		if (!file[i][0])
			i++;
		if (textures->north.path == NULL)
			textures->north.path = search_texture_id(file[i], "NO ");
		if (textures->south.path == NULL)
			textures->south.path = search_texture_id(file[i], "SO ");
		if (textures->east.path == NULL)
			textures->east.path = search_texture_id(file[i], "EA ");
		if (textures->west.path == NULL)
			textures->west.path = search_texture_id(file[i], "WE ");
		i++;
	}
	parse_colors(file, textures);
	return (textures);
}
