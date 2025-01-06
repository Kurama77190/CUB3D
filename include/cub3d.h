#ifndef	CUB3D_H
# define CUB3D_H

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

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

# define ERROR 1
# define SUCCESS 0


typedef struct s_parsing
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				r_c;
	int				g_c;
	int				b_c;
	int				r_f;
	int				g_f;
	int				b_f;
	char			**map;
	int				nb_pos; // calcul pas cette variable. un utils pour floodfill
	int				height_maps;
	int				lenth_maps;
	int				pos_x;
	int				pos_y;
	char			direction;
}					t_parsing;

typedef struct s_data
{
	char			**file;
	t_parsing		parsing;
}					t_data;



//////////////////////////////////////////////////////////////////
//                          PARSING							   //
////////////////////////////////////////////////////////////////

int				handle_parsing(int	argc, char **argv, t_data *data);
int				get_fd_in_tab(char *file, t_data *data);
int				get_map_in_tab(t_data *data);
int				get_value_fd(t_data *data);
int				check_valid_fd(t_data *data);
int				check_c(t_data *data);
int				check_f(t_data *data);
int				check_ea(t_data *data);
int				check_we(t_data *data);
int				check_so(t_data *data);
int				check_no(t_data *data);
int				check_map(t_data *data);
int				check_format_rgb(char *str);
int				check_double_param(t_data *data);
bool			valid_char(char c);
bool			valid_char_map(char *str);
int				check_valid_map(t_data *data);
int				replace_space_by_set(char **str, const char set);
int				check_valid_map_char(t_data *data);
char			**map_duplicate(char **map);
int				flood_fill_map_and_island(t_data *data);
bool			is_pos_char(char c);
void			init_pos_s_n(t_data *data, char **map, int x, int y);
void			init_pos_e_w(t_data *data, char **map, int x, int y);
int				check_space_in_map(t_data *data);
int				check_first_last_line(t_data *data);

void			ft_free_all(t_data *data);
void			print_tab(char **str);

# endif