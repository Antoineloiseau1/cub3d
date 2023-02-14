/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:41:09 by antoine           #+#    #+#             */
/*   Updated: 2023/02/14 09:27:04 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	map_check_start_position(char *map[])
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	map_check_char(char *map[])
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_str_isspace(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
	}
	return (1);
}

int	check_for_additionnal_content(char *map[])
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!map[i][0] && !ft_str_isspace(map[i]))
			break ;
		i++;
	}
	while (map[i] && (!map[i][0] || ft_str_isspace(map[i])))
		i++;
	if (!map[i])
		return (0);
	else
		return (1);
}
