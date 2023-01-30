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

char	*strcut_endl(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			tmp = s;
			s = ft_substr(tmp, 0, i);
			free (tmp);
			break ;
		}
		i++;
	}
	return (s);
}
