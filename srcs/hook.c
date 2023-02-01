/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:23:05 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/01 09:33:32 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h> 

#include "../includes/cub3d.h"

int	ft_close(void)
{
	exit(0);
}

int	key_handler(int key, t_mlx *mlx)
{
	(void)mlx; //////
	if (key == 53)
		exit(0);
/*	if ((key <= 2 && key >= 0) || key == 13)
	{
		ft_movement(key, mlx);
	}*/
	return (0);
}

void	hooking(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 0, ft_close, 0);
	mlx_key_hook(mlx->win, key_handler, mlx);
}
