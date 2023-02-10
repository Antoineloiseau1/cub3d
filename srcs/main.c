/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:53:13 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/10 10:02:59 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h> 

#include "../includes/cub3d.h"
#include "../includes/hook.h"
#include "../includes/raycasting.h" 
#include "../includes/utils.h"

void	mlx_values_init(t_data *data)
{
	void	*img;

	data->mlx.up = false;
	data->mlx.down = false;
	data->mlx.left = false;
	data->mlx.right = false;
	data->mlx.r_left = false;
	data->mlx.r_right = false;
	data->mlx.img = NULL;
	data->mlx.addr = NULL;
	data->mlx.win_height = 600;
	data->mlx.win_width = 800;
	img = mlx_xpm_file_to_image(data->mlx.mlx, data->textures->north.path, &data->textures->north.width, &data->textures->north.height );
	if (!img)
		error(1, "can't open texture");
	data->textures->north.addr = mlx_get_data_addr(img, &data->textures->north.bpp, &data->textures->north.line_l, &data->textures->north.endian);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	check_args(argc, argv);
	data = init_data(argv[1]);
	data->mlx.mlx = mlx_init();
	mlx_values_init(data);
	puts(dec_to_hexa(data->textures->ceil->red));
	get_player_position(data->map.map, data);
	get_initial_dir(data);
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.win_width,
			data->mlx.win_height, "cub3d");
	hooking(data);
	mlx_loop(data->mlx.mlx);
	free_data(data);
	return (0);
}
