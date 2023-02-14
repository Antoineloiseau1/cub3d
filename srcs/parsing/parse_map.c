/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:34:31 by antoine           #+#    #+#             */
/*   Updated: 2023/02/14 09:29:59 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h" 

char	*search_map(char *line)
{
	int	i;

	i = 0;
	if (!line || !ft_strlen(line))
		return (NULL);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (ft_strchr(line, '\t'))
		error(1, "tabs != space (and we don't accept tabs)");
	if (ft_strncmp(line + i, "NO ", 3)
		&& ft_strncmp(line + i, "EA ", 3) && ft_strncmp(line + i, "WE ", 3)
		&& ft_strncmp(line + i, "SO ", 3) && ft_strncmp(line + i, "F ", 2)
		&& ft_strncmp(line + i, "C ", 2) && line[i] != '\n')
		return (line);
	if (line[i] == '1' || line[i] == '0')
		return (line);
	return (NULL);
}

char	**copy_map(char *file[], int i)
{
	int		j;
	char	**map;

	map = malloc(sizeof(char *) * (tab_len(file + i) + 1));
	if (!map)
		return (NULL);
	j = 0;
	while (file[i])
	{
		map[j] = ft_strdup(file[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

char	**extract_map(char *file[])
{
	int		i;

	i = 0;
	while (file[i])
	{
		if (!file[i][0])
			i++;
		if (search_map(file[i]))
			break ;
		i++;
	}
	if (file[i] == NULL)
		return (NULL);
	return (copy_map(file, i));
}
