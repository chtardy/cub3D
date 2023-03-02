#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>
#include <stdio.h>

#include "./minilibx/mlx.h"
#include "./libft/libft.h"

typedef struct s_map
{
	char **map;
} 	t_mapstr;

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct t_num
{
	double time;
	double old_time;
	double frame_time;
	double plane_x;
	double plane_y;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double move_speed;
	double rot_speed;
	double start;
}	t_num;

typedef struct s_tex
{
	int	tex_x;
	int	tex_y;
	int buffer[720][1024];
	int *texture[8];
	int	texture_width;
	int	texture_height;
}	t_tex;

typedef struct s_game
{
	void		*mlx;
	void		*window;

	int			**map_ig;
	t_num		numig;
	t_data		imgig;
	t_tex		texig;
	int			window_height;
	int			window_width;

}	t_game ;

// parsing

int map_reader(t_game *game, char **argv, int flag);

// map declare

int map_declare(void);

// color

int	create_trgb(int t, int r, int g, int b);

// drawing

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_data img, int x, int draw_start, int draw_end, int color);

#endif