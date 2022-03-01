#include "../../includes/fdf.h"

static void	ft_calc_h(t_fdf *fdf, int j, int i)
{
	if (fdf->dx == 0)
	{
		fdf->draw_x = fdf->crd[j][i].xcrd * fdf->zoom + fdf->def_x;
		fdf->draw_y = (fdf->crd[j][i].ycrd + fdf->count)
			* fdf->zoom + fdf->def_y;
	}
	else
	{
		fdf->draw_x = (fdf->crd[j][i - 1].xcrd + fdf->count)
			* fdf->zoom + fdf->def_x;
		fdf->draw_y = (fdf->crd[j][i - 1].ycrd + fdf->dy
				* (fdf->crd[j][i - 1].xcrd + fdf->count
					- fdf->crd[j][i - 1].xcrd) / fdf->dx)
			* fdf->zoom + fdf->def_y;
	}
	if (fdf->dx == 0)
		fdf->count += fdf->dy / 100;
	else
		fdf->count += fdf->dx / 100;
	fdf->pnts_amount++;
}

static void	ft_calc_v(t_fdf *fdf, int j, int i)
{
	if (fdf->dx == 0)
	{
		fdf->draw_x = fdf->crd[j][i].xcrd * fdf->zoom + fdf->def_x;
		fdf->draw_y = (fdf->crd[j - 1][i].ycrd + fdf->count) * fdf->zoom
			+ fdf->def_y;
	}
	else
	{
		fdf->draw_x = (fdf->crd[j - 1][i].xcrd + fdf->count)
			* fdf->zoom + fdf->def_x;
		fdf->draw_y = (fdf->crd[j - 1][i].ycrd + fdf->dy
				* (fdf->crd[j - 1][i].xcrd + fdf->count
					- fdf->crd[j - 1][i].xcrd) / fdf->dx)
			* fdf->zoom + fdf->def_y;
	}
	if (fdf->dx == 0)
		fdf->count += fdf->dy / 100;
	else
		fdf->count += fdf->dx / 100;
	fdf->pnts_amount++;
}

static void	ft_fill_pix_v(t_fdf *fdf, int j, int i)
{
	int		p_clr;

	p_clr = (int)(fdf->draw_x) * 4 + (int)(fdf->draw_y) * 4 * fdf->hei;
	if (fdf->f_info[j][i] != NULL)
	{
		fdf->img.addr[p_clr] = fdf->crd[j - 1][i].clr->r;
		fdf->img.addr[p_clr + 1] = fdf->crd[j - 1][i].clr->g;
	}
	else
	{
		fdf->img.addr[p_clr] = fdf->crd[j][i].clr->r;
		fdf->img.addr[p_clr + 1] = fdf->crd[j][i].clr->g;
	}
	if (fdf->matrix[j][i] > fdf->matrix[j - 1][i]
	&& fdf->f_info[j - 1][i] == NULL)
		fdf->img.addr[p_clr + 2] = fdf->crd[j - 1][i].clr->b + (fdf->grad
				* (fdf->matrix[j][i] - fdf->matrix[j - 1][i])
				* fdf->pnts_amount);
	else if (fdf->matrix[j][i] < fdf->matrix[j - 1][i]
	&& fdf->f_info[j][i] == NULL)
		fdf->img.addr[p_clr + 2] = fdf->crd[j - 1][i].clr->b - (fdf->grad
				* (fdf->matrix[j - 1][i] - fdf->matrix[j][i])
				* fdf->pnts_amount);
	else
		fdf->img.addr[p_clr + 2] = fdf->crd[j][i].clr->b;
}

void	ft_draw_horiz(t_fdf *fdf, int j, int i)
{
	if (i > 0)
	{
		fdf->pnts_amount = 0;
		fdf->count = 0;
		fdf->dx = fdf->crd[j][i].xcrd - fdf->crd[j][i - 1].xcrd;
		fdf->dy = fdf->crd[j][i].ycrd - fdf->crd[j][i - 1].ycrd;
		while (fdf->pnts_amount < 100)
		{
			ft_calc_h(fdf, j, i);
			if (fdf->draw_x > 10 && fdf->draw_y > 10 && fdf->draw_x < fdf->hei
				&& fdf->draw_y < fdf->wid)
				ft_fill_pix_h(fdf, j, i);
		}
	}
}

void	ft_draw_vert(t_fdf *fdf, int j, int i)
{
	if (j > 0)
	{
		fdf->pnts_amount = 0;
		fdf->dx = fdf->crd[j][i].xcrd - fdf->crd[j - 1][i].xcrd;
		fdf->dy = fdf->crd[j][i].ycrd - fdf->crd[j - 1][i].ycrd;
		fdf->count = 0;
		while (fdf->pnts_amount < 100)
		{
			ft_calc_v(fdf, j, i);
			if (fdf->draw_x > 10 && fdf->draw_y > 10 && fdf->draw_x < fdf->hei
				&& fdf->draw_y < fdf->wid)
				ft_fill_pix_v(fdf, j, i);
		}
	}
}
