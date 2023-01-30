/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:51:52 by anloisea          #+#    #+#             */
/*   Updated: 2022/03/22 12:24:45 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	check;

	i = 0;
	check = c;
	while (s[i])
		i++;
	if (check == 0)
		return ((char *)s + i);
	while (i != -1)
	{
		if (check == s[i])
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
