/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:53:13 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/06 09:15:03 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h> 

#include "../includes/cub3d.h"
#include "../includes/hook.h"
#include "../includes/raycasting.h" 

int	main(int argc, char *argv[])
{
	t_data	*data;

	check_args(argc, argv);
	data = init_data(argv[1]);
	get_player_position(data->map.map, data);
	get_initial_dir(data);
	data->mlx.mlx = mlx_init();
	data->mlx.win_height = 600;
	data->mlx.win_width = 800;
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.win_width, data->mlx.win_height, "cub3d");
	ft_init_raycasting(data);
	hooking(data);
	mlx_loop(data->mlx.mlx);
	free_data(data); //// is this useful?
	return (0);
}
