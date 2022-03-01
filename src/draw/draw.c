#include "../../includes/fdf.h"

static void	ft_get_pix_clr(t_fdf *fdf, int j, int i)
{
	t_color	*clr;

	clr = (t_color *)malloc(sizeof(t_color));
	fdf->crd[j][i].clr = clr;
	fdf->crd[j][i].clr->r = ft_16to10(fdf->f_info[j][i], 0);
	fdf->crd[j][i].clr->g = ft_16to10(fdf->f_info[j][i], 2);
	fdf->crd[j][i].clr->b = ft_16to10(fdf->f_info[j][i], 4);
}

static void	ft_take_pix_clr(t_fdf *fdf, int j, int i)
{
	t_color	*clr;
	double	grad_pix;

	if (fdf->crd[j][i].clr)
		free(fdf->crd[j][i].clr);
	grad_pix = 200 / (fdf->maxh - fdf->minh);
	fdf->grad = grad_pix / 100;
	clr = (t_color *)malloc(sizeof(t_color));
	fdf->crd[j][i].clr = clr;
	fdf->crd[j][i].clr = clr;
	fdf->crd[j][i].clr->r = fdf->clr.r;
	fdf->crd[j][i].clr->g = 50 + (grad_pix * ((fdf->matrix[j][i]) - fdf->minh));
	fdf->crd[j][i].clr->b = fdf->clr.b;
}

void	ft_pix_map(t_fdf *fdf, int j, int i)
{
	while (++j < fdf->height)
	{
		i = -1;
		while (++i < fdf->width)
		{
			if (fdf->f_info[j][i] == NULL)
				ft_take_pix_clr(fdf, j, i);
			else
				ft_get_pix_clr(fdf, j, i);
		}
	}
}

static void	ft_draw_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 10, 0x47F8DF,
		"w/s -- X rot");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 25, 0x47F8DF,
		"q/e -- Y rot");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 40, 0x47F8DF,
		"a/d -- Z rot");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 10, 0x47F8DF,
		"i -- ISO");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 25, 0x47F8DF,
		"p -- perspective");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 340, 10, 0x47F8DF,
		"arrows -- move proj");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 340, 25, 0x47F8DF,
		"+/- -- zoom");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 510, 10, 0x47F8DF,
		"z -- increase the effect of height");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 510, 25, 0x47F8DF,
		"x -- reduce the effect of height");
}

void	ft_draw(t_fdf *fdf, int j, int i)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero((void *)fdf->img.addr, fdf->hei * fdf->wid * 4);
	while (j < fdf->height)
	{
		i = 0;
		while (i < fdf->width)
		{
			ft_draw_horiz(fdf, j, i);
			ft_draw_vert(fdf, j, i);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->img.img_ptr, 0, 0);
	ft_draw_menu(fdf);
}
