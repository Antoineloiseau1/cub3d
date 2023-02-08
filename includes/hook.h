/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:25:59 by mmidon            #+#    #+#             */
/*   Updated: 2023/02/08 07:43:07 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# define ROTATE_SPEED 0.1
# define FRONT_SPEED 0.23
# define BACK_SPEED 0.18
# define TRANSLATE_SPEED 0.15

#include "cub3d.h" 

void    hooking(t_data *data);
int move(t_data *data);

#endif
