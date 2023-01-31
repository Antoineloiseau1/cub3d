/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:55:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/31 13:00:05 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	**copy_lst_in_file(t_list *lst)
{
	char	**file;
	int		i;
	t_list	*tmp;

	file = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	i = 0;
	tmp = lst;
	while (tmp)
	{
		file[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	file[i] = NULL;
	ft_lstclear(&lst);
	return (file);
}

char	**extract_file_content(int fd)
{
	t_list	*lst;
	t_list	*tmp;
	char	**file;

	lst = ft_lstnew(get_next_line(fd));
	if (lst->content == NULL)
	{
		free(lst);
		return (NULL);
	}
	tmp = lst;
	while (tmp->content)
	{
		ft_lstadd_back(&lst, ft_lstnew(get_next_line(fd)));
		tmp = tmp->next;
	}
	file = copy_lst_in_file(lst);
	file = cut_endl(file);
	return (file);
}

t_data	*init_data(char *file)
{
	t_data	*data;
	int		fd;

	fd = check_opening(file);
	data = malloc(sizeof(t_data));
	if (!data)
		error(-1, "failed to allocate data");
	data->file = extract_file_content(fd);
	if (data->file == NULL)
	{
		free(data);
		error(-1, "file is empty");
	}
	data->textures = parse_textures(data->file);
	if (check_textures(data->textures))
	{
		data->map = NULL;
		free_data(data);
		error(1, "textures undifined");
	}
	data->map = extract_map(data->file);
	close(fd);
	if (!data->map)
	{
		free_data(data);
		error(2, "map not found in file");
	}
	check_map(data);
	return (data);
}
