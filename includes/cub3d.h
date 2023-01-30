/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:59:21 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/30 13:27:51 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}t_textures;

typedef struct	s_data
{
	char		**file;
	char		**map;
	t_textures	*textures;
}t_data;

//CHECKS
void	check_args(int argc, char *argv[]);
void	check_file_format(char *file_name);
int		check_opening(char *file);
void	check_map(char *map[]);

//DATA
t_data	*init_data(char *file);

//PARSER
t_textures	*parse_textures(char *file[]);
char		*get_texture_path(char *line);

//UTILS
int		is_ok_for_map(char c);

//ERRORS
void	error(int errnum, const char *msg);

//FREE
void	free_data(t_data *data);

#endif