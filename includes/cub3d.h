/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 07:59:21 by anloisea          #+#    #+#             */
/*   Updated: 2023/02/13 11:43:12 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>

# define ROTATE_SPEED 0.04
# define FRONT_SPEED 0.05
# define BACK_SPEED 0.05
# define TRANS_SPEED 0.05
# define ESCAPE 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define L_ARROW 123
# define R_ARROW 124

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	total;
}t_color;

typedef struct s_image
{
	char	*path;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_textures
{
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
	t_color	*floor;
	t_color	*ceil;
}t_textures;

typedef struct s_mlx
{
	int			line_l;
	int			endian;
	int			bpp;
	int			old_x;
	bool		up;
	bool		down;
	bool		left;
	bool		right;
	bool		r_left;
	bool		r_right;
	int			win_width;
	int			win_height;
	void		*img;
	void		*addr;
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct s_map
{
	char	**map;
	t_coord	pos;
	t_coord	dir;
	t_coord	plane;
	t_coord	ray_dir;
	t_coord	side_dist;
	t_coord	delta_dist;
	double	perp_wall_dist;
	int		pixel;
	int		step_x;
	int		step_y;
	int		tile_x;
	int		tile_y;
	double	wall_hit;
	int		tex_x;
	int		draw_start;
	int		draw_end;
}			t_map;

typedef struct s_data
{
	char		**file;
	t_textures	*textures;
	t_map		map;
	t_mlx		mlx;
}t_data;

//CHECKS
void		check_args(int argc, char *argv[]);
int			check_file_extension(char *file_name, char *ext);
int			check_opening(char *file);
void		check_map(t_data *data);
int			check_textures(t_textures *textures);
int			map_check_start_position(char *map[]);
int			map_check_char(char *map[]);
int			check_for_additionnal_content(char *map[]);
void		check_if_textures_parsed(t_data *data);
void		check_file(t_data *data);

//DATA
t_data		*init_data(char *file);

//PARSER
t_textures	*parse_textures(char *file[]);
char		*get_texture_path(char *line);
char		**extract_map(char *file[]);
char		**split_and_trim_raw_values(char *raw_values);

//UTILS
int			is_ok_for_map(char c);

//ERRORS
void		error(int errnum, const char *msg);

//FREE
void		free_data(t_data *data);
void		free_chartab(char *tab[]);
void		free_textures(t_textures *textures);

#endif
