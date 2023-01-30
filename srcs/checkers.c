/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:57:19 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/30 13:35:21 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

void	check_args(int argc, char *argv[])
{
	if (argc != 2)
		error(1, "usage: ./cub3d [map].cub");
	check_file_format(argv[1]);
}

void	check_file_format(char *file_name)
{
	if (ft_strnstr(file_name + ft_strlen(file_name) - 4, ".cub", 4) == NULL)
		error(1, "usage: ./cub3d [map].cub");
}

int	check_opening(char *file)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		perror(file);
		exit(-1);
	}
	else 
		return (fd);
}

void	map_check_first_and_last_line(char *map[])
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while(map[line][i])
	{
		if (map[line][i] == '1' || map[line][i] == ' ' || map[line][i] == '\n')
			i++;
		else
			error(2, "map is not closed");
	}
	i = 0;
	line = tab_len(map) - 1;
	while(map[line][i])
	{
		if (map[line][i] == '1' || map[line][i] == ' ' || map[line][i] == '\n')
			i++;
		else
			error(2, "map is not closed");
	}
	
}

void	map_check_ones_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] && line[i] != '1')
		error(2, "map is not closed");
	i = ft_strlen(line) - 1;
	while (i != 0 && (line[i] == ' ' || line[i] == '\n'))
		i--;
	if (line[i] && line[i] != '1')
		error(2, "map is not closed");
	
}

void	map_check_zeros_in_line(char *map[], int line)
{
	int	i;

	i = 0;
	while (map[line][i])
	{
		if (map[line][i] == '0')
		{
			if (ft_isspace(map[line][i - 1])|| !map[line][i - 1])
				error(2, "map is not closed");
			if (ft_isspace(map[line][i + 1]) || !map[line][i + 1])
				error(2, "map is not closed");
			if (ft_isspace(map[line - 1][i]) || !map[line - 1][i])
				error(2, "map is not closed");
			if (ft_isspace(map[line + 1][i]) || !map[line + 1][i])
				error(2, "map is not closed");
		}
		i++;
	}
}

void	map_check_intermediate_lines(char *map[])
{
	int	line;

	line = 1;
	while (line < tab_len(map) - 1)
	{
		map_check_ones_in_line(map[line]);
		map_check_zeros_in_line(map, line);
		line++;
	}
}

void	map_check_start_position(char *map[])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (ft_strchrset(map[i], "NSEW") != -1)
			count++;
		i++;
	}
	if (count > 1 || count < 1)
		error(2, "there must be one position in map");
}

void	map_check_char(char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_ok_for_map(map[i][j]))
				error(2, "undesired char in map");
			j++;
		}
		i++;
	}
}

void	check_map(char *map[])
{
	map_check_char(map);
	map_check_start_position(map);
	map_check_first_and_last_line(map);
	map_check_intermediate_lines(map);
}