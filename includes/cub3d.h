/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:59:21 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/31 12:46:39 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}t_color;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_color	*floor;
	t_color	*ceil;
}t_textures;

typedef struct s_data
{
	char		**file;
	char		**map;
	t_textures	*textures;
}t_data;

//CHECKS
void		check_args(int argc, char *argv[]);
void		check_file_extension(char *file_name);
int			check_opening(char *file);
void		check_map(t_data *data);
int			check_textures(t_textures *textures);
int			map_check_start_position(char *map[]);
int			map_check_char(char *map[]);
int			check_for_additionnal_content(char *map[]);

//DATA
t_data		*init_data(char *file);

//PARSER
t_textures	*parse_textures(char *file[]);
char		*get_texture_path(char *line);
char		**extract_map(char *file[]);

//UTILS
int			is_ok_for_map(char c);

//ERRORS
void		error(int errnum, const char *msg);

//FREE
void		free_data(t_data *data);
void		free_chartab(char *tab[]);
void		free_textures(t_textures *textures);

#endif