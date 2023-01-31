/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:34:31 by antoine           #+#    #+#             */
/*   Updated: 2023/01/31 15:09:47 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

char	*search_map(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '1')
		return (line);
	if (line[i] == '0')
		return (NULL);
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
