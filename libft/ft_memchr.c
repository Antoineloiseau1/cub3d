/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:55:18 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/01 12:57:08 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			check;
	unsigned const char		*str;

	i = 0;
	check = c;
	str = s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (str[i] == check)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
