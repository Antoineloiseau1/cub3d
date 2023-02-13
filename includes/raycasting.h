/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:00:58 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/13 10:39:32 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h" 

int		ft_init_raycasting(t_data *data);
int		ft_raycasting(t_data *data);
void	get_initial_dir(t_data *data);
void	get_player_position(char **map, t_data *data);
double	ft_abs(double nbr);
void	ft_init_data(t_data *data, int pixel);
void	ft_set_step(t_data *data);
void	line_pixel_put(t_data *data, int start, int end, int color);
void	wall_pixel_put(t_data *data, float factor, t_image current);
void	color_choice(t_data *data);

#endif
