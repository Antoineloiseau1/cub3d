/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:00:58 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/06 08:40:57 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

#include "cub3d.h" 

int 	ft_init_raycasting(t_data *data);
int 	ft_raycasting(t_data *data);
void    get_initial_dir(t_data *data);
void    get_player_position(char **map, t_data *data);

#endif
