/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:37:51 by antoine           #+#    #+#             */
/*   Updated: 2022/12/08 17:37:56 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a copy of a tab and returns it.*/
char	**ft_tabdup(char **t_str)
{
	char	**copy;
	int		i;

	copy = malloc((tab_len(t_str) + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (t_str[i])
	{
		copy[i] = ft_strdup(t_str[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
