#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_color
{
	int				r;
	int				b;
	int				g;
}					t_color;

typedef struct s_coord
{
	double			xcrd;
	double			ycrd;
	double			zcrd;
	int				clr_key;
	t_color			*clr;
}					t_coord;

typedef struct s_fdf
{
	int		width;
	int		height;
	double	**matrix;
	char	***f_info;
	void	*mlx_ptr;
	void	*win_ptr;
	int		hei;
	double	grad;
	int		wid;
	int		zoom;
	int		def_x;
	int		def_y;
	double	dx;
	double	dy;
	double	draw_x;
	double	draw_y;
	double	maxh;
	double	minh;
	int		press_1;
	int		press_2;
	int		pre_y;
	int		pre_x;
	char	projection;
	double	alfa;
	double	betta;
	double	gamma;
	double	count;
	int		pnts_amount;

	t_coord	**crd;
	t_img	img;
	t_color	clr;
}				t_fdf;

#endif