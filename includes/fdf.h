#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include "utils.h"

//DEFINES in order to be able to port other keys to another OS

# define B_W 119
# define B_S 115
# define B_A 97
# define B_D 100
# define B_AR_U 65362
# define B_AR_D 65364
# define B_AR_L 65361
# define B_AR_R 65363
# define B_ESC 65307
# define B_Q 113
# define B_E 101
# define B_I 105
# define B_P 112
# define B_MINUS 45
# define B_PLUS 61
# define B_Z 122
# define B_X 120
# define B_SPACE 32
# define B_TAB 65289
# define B_CTR 65507

# define HEIGHT 1000
# define WIDTH 1000

void	ft_read_map(t_fdf *fdf, int fd, char *map);
void	ft_init_fdf(t_fdf *fdf);
void	ft_pix_map(t_fdf *fdf, int j, int i);
void	ft_draw(t_fdf *fdf, int j, int i);
void	ft_draw_vert(t_fdf *fdf, int j, int i);
void	ft_draw_horiz(t_fdf *fdf, int j, int i);
void	ft_fill_pix_h(t_fdf *fdf, int j, int i);
void	ft_rotate(t_fdf *fdf, int j, int i);
int		ft_mouse_press(int key, int x, int y, t_fdf *fdf);
int		ft_mouse_release(int key, int x, int y, t_fdf *fdf);
int		ft_mouse_motion(int x, int y, t_fdf *fdf);

#endif