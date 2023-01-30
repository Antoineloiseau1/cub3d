/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:24:13 by anloisea          #+#    #+#             */
/*   Updated: 2022/03/22 16:30:45 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checkset(char c, char set)
{
	if (c == set)
		return (1);
	else
		return (0);
}

static char	*ft_strcut(const char *s, const char *temp)
{
	int		size;
	char	*dup;
	int		i;

	size = ft_strlen(temp) - ft_strlen(s);
	dup = malloc((size + 1) * sizeof(*dup));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (temp != s)
	{	
		dup[i] = *temp;
		i++;
		temp++;
	}
	dup[i] = 0;
	return (dup);
}

static int	ft_count_words(const char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	if (ft_checkset(s[i], c) && s[i])
		i++;
	while (s[i])
	{
		while (!ft_checkset(s[i], c) && s[i])
			i++;
		word++;
		while (ft_checkset(s[i], c) && s[i])
			i++;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char		**split;
	int			index;
	const char	*temp;

	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	index = 0;
	while (ft_checkset(*s, c) && *s)
		s++;
	while (*s)
	{
		temp = s;
		while (!ft_checkset(*s, c) && *s)
			s++;
		split[index] = ft_strcut(s, temp);
		index++;
		while (ft_checkset(*s, c) && *s)
			s++;
	}
	split[index] = 0;
	return (split);
}
