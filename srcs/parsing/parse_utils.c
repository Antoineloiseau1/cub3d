/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:36 by antoine           #+#    #+#             */
/*   Updated: 2023/01/31 15:32:48 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"

char	**split_and_trim_raw_values(char *raw_values)
{
	char	**values;
	char	*tmp;
	int		i;

	values = ft_split(raw_values, ',');
	i = 0;
	while (values[i])
	{
		tmp = values[i];
		values[i] = ft_strtrim(values[i], " \t");
		free(tmp);
		i++;
	}
	if (tab_len(values) != 3)
	{
		free_chartab(values);
		return (NULL);
	}
	return (values);
}
