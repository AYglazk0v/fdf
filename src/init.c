/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:23:55 by gtaggana          #+#    #+#             */
/*   Updated: 2022/03/03 21:23:56 by ayglazko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_init_const(t_fdf *fdf)
{
	fdf->hei = HEIGHT;
	fdf->wid = WIDTH;
	fdf->zoom = HEIGHT / 4 / fdf->height;
	fdf->def_x = HEIGHT / 2;
	fdf->def_y = WIDTH / 2;
	fdf->alfa = 0;
	fdf->betta = 0;
	fdf->gamma = 0;
	fdf->projection = 'I';
	fdf->clr.r = 0;
	fdf->clr.g = 200;
	fdf->clr.b = 255;
	fdf->press_1 = 0;
	fdf->pre_x = 0;
	fdf->pre_y = 0;
	fdf->press_2 = 0;
	fdf->maxh = -2147483648;
	fdf->minh = 2147483647;
}

static void	ft_init_pix(t_fdf *fdf, int j, int i)
{
	t_coord	**crd;

	crd = (t_coord **) malloc(sizeof(t_coord *) * fdf->height);
	if (!crd)
		ft_errors("Error malloc\n");
	while (++j < fdf->height)
	{
		i = -1;
		crd[j] = (t_coord *)malloc(sizeof(t_coord) * fdf->width);
		if (!crd[j])
			ft_errors("Error malloc\n");
		while (++i < fdf->width)
		{
			crd[j][i].ycrd = j - fdf->height / 2;
			crd[j][i].xcrd = i - fdf->width / 2;
			crd[j][i].zcrd = fdf->matrix[j][i];
			if (fdf->matrix[j][i] > fdf->maxh)
				fdf->maxh = fdf->matrix[j][i];
			if (fdf->matrix[j][i] < fdf->minh)
				fdf->minh = fdf->matrix[j][i];
			crd[j][i].clr_key = 0;
		}
	}
	fdf->crd = crd;
}

void	ft_init_fdf(t_fdf *fdf)
{
	ft_init_const(fdf);
	ft_init_pix(fdf, -1, 0);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img_ptr,
			&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
}
