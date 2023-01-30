/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:55:10 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/01 12:55:29 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	check;

	i = 0;
	check = c;
	while (s[i])
	{
		if (check == s[i])
			return ((char *)s + i);
		i++;
	}
	if (check == 0)
		return ((char *)s + i);
	return (NULL);
}
