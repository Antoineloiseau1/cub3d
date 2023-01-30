/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:36:44 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/01 16:00:01 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}

static char	*ft_revstr(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[0] == '-')
		i++;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	str = (char *)malloc((ft_nblen(nb) + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	str[i] = nb + 48;
	str[i + 1] = 0;
	ft_revstr(str);
	return (str);
}
