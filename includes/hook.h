/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:25:59 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/14 13:44:20 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "cub3d.h" 

void	hooking(t_data *data);
int		move(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	mouse_rotate_right(t_data *data);
void	mouse_rotate_left(t_data *data);

#endif
