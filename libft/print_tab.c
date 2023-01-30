/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:18:33 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/30 12:29:07 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab(char *tab[])
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		i++;
	}
	write(1, "\n", 1);
}