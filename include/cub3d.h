#ifndef	CUB4D_H
# define CUB4D_H

# include <fcntl.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <mlx.h>
# include <stdbool.h>

# include "../external/GNL/include/get_next_line.h"
# include "ft_printf.h"
# include "libft.h"


typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_wall
{
	t_img		wall_n;
	t_img		wall_s;
	t_img		wall_e;
	t_img		wall_w;
}				t_wall;	

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
	double		fov;
}				t_player;


typedef struct s_ray
{
	double		x;
	double		y;
	double		dir;
	double		dist;
}				t_ray;


typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;


typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_data
{
	t_wall		wall;
	t_player	player;
	t_ray		ray;
	t_map		map;
	t_mlx		mlx;
}				t_data;


//////////////////////////////////////////////////////////////////
//                          PARSING							   //
////////////////////////////////////////////////////////////////




# endif