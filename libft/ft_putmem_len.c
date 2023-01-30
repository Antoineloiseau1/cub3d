/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:43:29 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/08 13:16:47 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem_len(unsigned long int mem, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (mem > 15)
		ft_putmem_len(mem / 16, len);
	ft_putchar_len(hexa[mem % 16], len);
}
