/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:19:10 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/01 17:04:17 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*tmp_s;
	char		*tmp_d;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	tmp_s = src;
	tmp_d = dst;
	i = 0;
	if (tmp_d < tmp_s)
	{	
		while (len > 0)
		{
			tmp_d[i] = tmp_s[i];
			len--;
			i++;
		}
	}
	while (len > 0)
	{
		tmp_d[len - 1] = tmp_s[len - 1];
		len--;
	}
	return (dst);
}
