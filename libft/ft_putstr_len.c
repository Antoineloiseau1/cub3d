/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:24:01 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/08 11:50:13 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_len(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", ft_strlen("(null)"));
		(*len) += ft_strlen("(null)");
		return ;
	}
	while (str[i])
	{
		ft_putchar_len(str[i], len);
		i++;
	}
}
