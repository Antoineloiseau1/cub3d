/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:00:58 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/31 12:32:04 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	error(int errnum, const char *msg)
{
	ft_putstr_fd("Error\nCub3d: ", 2);
	ft_putstr_fd((char *)msg, 2);
	ft_putchar_fd('\n', 2);
	exit(errnum);
}
