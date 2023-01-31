/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:41:09 by antoine           #+#    #+#             */
/*   Updated: 2023/01/31 15:23:39 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	map_check_start_position(char *map[])
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

int	check_for_additionnal_content(char *map[])
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!map[i][0])
			break ;
		i++;
	}
	while (map[i] && !map[i][0])
		i++;
	if (!map[i])
		return (0);
	else
		return (1);
}
