#include "../includes/fdf.h"

static void	ft_rotate_help(t_fdf *fdf, double tmp, int j, int i)
{
	fdf->crd[j][i].xcrd = (i - fdf->width / 2) * cos(fdf->betta)
		- (j - fdf->height / 2) * sin(fdf->betta);
	fdf->crd[j][i].ycrd = (i - fdf->width / 2) * sin(fdf->betta)
		+ (j - fdf->height / 2) * cos(fdf->betta);
	fdf->crd[j][i].zcrd = (fdf->crd[j][i].ycrd) * sin(fdf->alfa)
		+ (fdf->matrix[j][i] * cos(fdf->alfa));
	fdf->crd[j][i].ycrd = (fdf->crd[j][i].ycrd) * cos(fdf->alfa)
		+ (fdf->matrix[j][i] * -1 * sin(fdf->alfa));
	tmp = (fdf->crd[j][i].xcrd) * cos(fdf->gamma)
		- (fdf->crd[j][i].zcrd) * sin(fdf->gamma);
	fdf->crd[j][i].zcrd = (fdf->crd[j][i].xcrd)
		* sin(fdf->gamma) + (fdf->crd[j][i].zcrd) * cos(fdf->gamma);
		fdf->crd[j][i].xcrd = tmp;
}

void	ft_rotate(t_fdf *fdf, int j, int i)
{
	double	tmp;

	tmp = 0.0;
	while (++j < fdf->height)
	{
		i = -1;
		while (++i < fdf->width)
		{
			ft_rotate_help(fdf, tmp, j, i);
			if (fdf->projection == 'P')
			{
				fdf->crd[j][i].ycrd = fdf->crd[j][i].ycrd
					/ (-0.01 * fdf->crd[j][i].zcrd + 1);
				fdf->crd[j][i].xcrd = fdf->crd[j][i].xcrd
					/ (-0.01 * fdf->crd[j][i].zcrd + 1);
				fdf->crd[j][i].zcrd = fdf->crd[j][i].zcrd
					/ (-0.01 * fdf->crd[j][i].zcrd + 1);
			}
		}
	}
}
