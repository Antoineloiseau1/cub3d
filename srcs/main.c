/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:53:13 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/01 12:05:45 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h> 

#include "../includes/cub3d.h"
#include "../includes/hook.h"
#include "../includes/raycasting.h" 

int	main(int argc, char *argv[])
{
	t_data	*data;

	check_args(argc, argv);
	data = init_data(argv[1]);
	data->mlx.mlx = mlx_init();

	data->mlx.win = mlx_new_window(data->mlx.mlx, 400, 400, "aled");
	ft_init_raycasting(data->map.map, data);
	hooking(&data->mlx);
	mlx_loop(data->mlx.mlx);
	free_data(data); //// is this useful?
	return (0);
}
