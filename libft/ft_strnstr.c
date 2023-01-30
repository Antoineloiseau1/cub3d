/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:57:37 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/05 10:53:48 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	else if (!haystack[i])
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && k < len && haystack[k])
		{
			k++;
			j++;
		}
		if (needle[j] == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
