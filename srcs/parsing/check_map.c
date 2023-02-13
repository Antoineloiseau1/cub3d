/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:57:19 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/13 13:04:49 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	map_check_first_and_last_line(char *map[])
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (map[line][i])
	{
		if (map[line][i] == '1' || map[line][i] == ' ' || map[line][i] == '\n')
			i++;
		else
			return (1);
	}
	i = 0;
	line = tab_len(map) - 1;
	while (map[line][i])
	{
		if (map[line][i] == '1' || map[line][i] == ' ' || map[line][i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	map_check_ones_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] && line[i] != '1')
		return (1);
	i = ft_strlen(line) - 1;
	while (i != 0 && (line[i] == ' ' || line[i] == '\n'))
		i--;
	if (line[i] && line[i] != '1')
		return (1);
	return (0);
}

int	map_check_zeros_in_line(char *map[], int line)
{
	int	i;

	i = 0;
	while (map[line][i])
	{
		if (map[line][i] == '0')
		{
			if (ft_isspace(map[line][i - 1]))
				return (1);
			if (map[line][i] && (!map[line][i + 1]
						|| ft_isspace(map[line][i + 1])))
				return (1);
			if (!(i < ft_strlen(map[line - 1])) || (!map[line - 1][i]
				|| ft_isspace(map[line - 1][i])))
				return (1);
			if (!(i < ft_strlen(map[line + 1])) || (!map[line + 1][i]
				|| ft_isspace(map[line + 1][i])))
				return (1);
		}
		i++;
	}
	return (0);
}

int	map_check_intermediate_lines(char *map[])
{
	int	line;

	line = 1;
	while (line < tab_len(map) - 1)
	{
		if (map_check_ones_in_line(map[line]))
			return (1);
		if (map_check_zeros_in_line(map, line))
			return (1);
		line++;
	}
	return (0);
}

void	check_map(t_data *data)
{
	if (check_for_additionnal_content(data->map.map))
	{
		free_data(data);
		error(2, "unexpected line(s) after map");
	}
	if (map_check_char(data->map.map))
	{
		free_data(data);
		error(2, "unexpected char in map");
	}
	if (map_check_start_position(data->map.map))
	{
		free_data(data);
		error(2, "there must be one and only position in map");
	}
	if (map_check_first_and_last_line(data->map.map))
	{
		free_data(data);
		error(2, "map is not closed [1]");
	}
	if (map_check_intermediate_lines(data->map.map))
	{
		free_data(data);
		error(2, "map is not closed [2]");
	}
}
