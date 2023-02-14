/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:37:38 by antoine           #+#    #+#             */
/*   Updated: 2023/02/14 14:11:26 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	check_args(int argc, char *argv[])
{
	char	**file;
	char	*file_name;
	char	*file_extension;

	if (argc != 2)
		error(1, "usage: ./cub3d [file].cub");
	if (!ft_strlen(argv[1]))
		error(1, ": No such file or directory");
	file = ft_split(argv[1], '/');
	file_name = file[tab_len(file) - 1];
	file_extension = (ft_strchr(file_name, '.'));
	if (!file_extension)
	{
		free_chartab(file);
		error(1, "no extension given to file");
	}
	if (check_file_extension(file_name, file_extension))
	{
		free_chartab(file);
		error(1, "file must be [file].cub");
	}
	free_chartab(file);
}

int	check_file_extension(char *file_name, char *ext)
{
	if (ft_strcmp(ext, ".cub"))
		return (1);
	if (!ft_strcmp(file_name, ".cub"))
		return (1);
	return (0);
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
	if (textures->north.path == NULL)
		return (1);
	if (textures->south.path == NULL)
		return (1);
	if (textures->east.path == NULL)
		return (1);
	if (textures->west.path == NULL)
		return (1);
	return (0);
}
