/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:55:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/30 13:34:04 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	**extract_file_content(int fd)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	char 	**file;

	lst = ft_lstnew(get_next_line(fd));
	if (lst->content == NULL)
		return (NULL);
	tmp = lst;
	while (tmp->content)
	{
		ft_lstadd_back(&lst, ft_lstnew(get_next_line(fd)));
		tmp = tmp->next;
	}
	file = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	i = 0;
	while (lst)
	{
		file[i] = lst->content;
		i++;
		lst = lst->next;
	}
	file[i] = NULL;
	ft_lstclear(&lst);
	return(file);
}

char	**extract_map(char *file[])
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	while (file[i] && (file[i][0] != '1' && !ft_isspace(file[i][0])))
		i++;
	while (file[i] && file[i][0] == '\n')
		i++;
	if (file[i] == NULL)
		error(3, "map not found on file");
	map = malloc(sizeof(char *) * (tab_len(file + i) + 1));
	if (!map)
		exit(1);
	j = 0;
	while (file[i])
	{
		map[j] = ft_strdup(file[i]);
		j++;
		i++;
	}
	map[j] = NULL;
	return (map);
}

t_data	*init_data(char *file)
{
	t_data	*data;
	int		fd;
	
	fd = check_opening(file);
	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->file = extract_file_content(fd);
	data->textures = parse_textures(data->file);
	data->map = extract_map(data->file);
	close(fd);
	check_map(data->map);
	return (data);
}
