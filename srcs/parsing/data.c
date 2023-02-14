/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:55:30 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/14 09:39:47 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/utils.h"
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

int	atoi_base(char *str)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
		{
			result *= 16;
			result += str[i] - '0';
		}
		if (ft_tolower(str[i]) <= 'f' && ft_tolower(str[i]) >= 'a')
		{
			result *= 16;
			result += ft_tolower(str[i]) - 'a' + 10;
		}
	}
	return (result);
}

void	assemble_colors(t_color *color)
{
	char	*tmp1;
	char	*tmp2;
	char	*result;

	tmp1 = dec_to_hexa(color->red);
	tmp2 = dec_to_hexa(color->green);
	result = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	tmp1 = result;
	tmp2 = dec_to_hexa(color->blue);
	result = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	tmp1 = ft_strjoin("00", result);
	free(result);
	color->total = atoi_base(tmp1);
	free(tmp1);
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
	check_file(data);
	data->textures = parse_textures(data->file);
	check_if_textures_parsed(data);
	assemble_colors(data->textures->ceil);
	assemble_colors(data->textures->floor);
	data->map.map = extract_map(data->file);
	close(fd);
	if (!data->map.map)
	{
		free_data(data);
		error(2, "map not found in file");
	}
	check_map(data);
	return (data);
}
