/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:36 by antoine           #+#    #+#             */
/*   Updated: 2023/02/13 11:20:10 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"

void	rev(char *dest)
{
	int		len;
	int		i;
	char	tmp;

	i = 0;
	len = ft_strlen(dest);
	while (i < len / 2)
	{
		tmp = dest[i];
		dest[i] = dest[len - i - 1];
		dest[len - i - 1] = tmp;
		i++;
	}
}

char	*dec_to_hexa(int n)
{
	char	temp;
	int		i;
	char	*hexa;

	if (n == 0)
		return (ft_strdup("00"));
	hexa = malloc(sizeof(char) * 10);
	i = -1;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
		{
			hexa[++i] = temp + 48;
			if ((n / 16) % 16 == 0)
				hexa[++i] = '0';
		}
		else
			hexa[++i] = temp + 55;
		n = n / 16;
	}
	hexa[++i] = '\0';
	rev(hexa);
	return (hexa);
}

int	check_comas(char *values)
{
	int	coma;
	int	i;

	coma = 0;
	i = 0;
	while (values[i])
	{
		if (values[i] == ',')
			coma++;
		i++;
	}
	if (coma != 2)
		return (1);
	return (0);
}

int	check_color(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

char	**split_and_trim_raw_values(char *raw_values)
{
	char	**values;
	char	*tmp;
	int		i;

	if (check_comas(raw_values))
		return (NULL);
	values = ft_split(raw_values, ',');
	i = -1;
	while (values[++i])
	{
		tmp = values[i];
		values[i] = ft_strtrim(values[i], " \t");
		if (check_color(values[i]))
		{
			free_chartab(values);
			return (NULL);
		}
		free(tmp);
	}
	if (tab_len(values) != 3)
	{
		free_chartab(values);
		return (NULL);
	}
	return (values);
}
