/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_endl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:00:24 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/24 15:01:42 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**cut_endl(char **strings)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (strings[i])
	{
		j = 0;
		while (strings[i][j])
		{
			if (strings[i][j] == '\n')
			{
				tmp = strings[i];
				strings[i] = ft_substr(tmp, 0, j);
				free (tmp);
				break ;
			}
			j++;
		}
		i++;
	}
	return (strings);
}
