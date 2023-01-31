/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:37:38 by antoine           #+#    #+#             */
/*   Updated: 2023/01/31 12:39:19 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	check_args(int argc, char *argv[])
{
	if (argc != 2)
		error(1, "usage: ./cub3d [map].cub");
	check_file_extension(argv[1]);
}

void	check_file_extension(char *file_name)
{
	if (!ft_strnstr(file_name + ft_strlen(file_name) - 4, ".cub", 4))
		error(1, "file extension must be .cub");
}

int	check_opening(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\ncub3d: ", 2);
		perror(file);
		exit(-1);
	}
	else
		return (fd);
}

int	check_textures(t_textures *textures)
{
	if (textures->ceil == NULL)
		return (1);
	if (textures->floor == NULL)
		return (1);
	if (textures->north == NULL)
		return (1);
	if (textures->south == NULL)
		return (1);
	if (textures->east == NULL)
		return (1);
	if (textures->west == NULL)
		return (1);
	return (0);
}
