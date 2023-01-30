/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:54:38 by antoine           #+#    #+#             */
/*   Updated: 2022/04/08 13:18:15 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_len(unsigned int n, int *len)
{
	if (n > 9)
		ft_putunbr_len(n / 10, len);
	ft_putchar_len(n % 10 + '0', len);
}
