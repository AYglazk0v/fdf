/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:23:40 by gtaggana          #+#    #+#             */
/*   Updated: 2022/03/03 21:23:41 by ayglazko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_fill_pix_h(t_fdf *fdf, int j, int i)
{
	int	p_clr;

	p_clr = (int)(fdf->draw_x) * 4 + (int)(fdf->draw_y) * 4 * fdf->hei;
	if (fdf->f_info[j][i] != NULL)
	{
		fdf->img.addr[p_clr] = fdf->crd[j][i - 1].clr->r;
		fdf->img.addr[p_clr + 1] = fdf->crd[j][i - 1].clr->g;
	}
	else
	{
		fdf->img.addr[p_clr] = fdf->crd[j][i].clr->r;
		fdf->img.addr[p_clr + 1] = fdf->crd[j][i].clr->g;
	}
	if ((fdf->matrix[j][i] > fdf->matrix[j][i - 1])
	&& fdf->f_info[j][i - 1] == NULL)
		fdf->img.addr[p_clr + 2] = fdf->crd[j][i - 1].clr->b + (fdf->grad
				* (fdf->matrix[j][i] - fdf->matrix[j][i - 1])
				* (double)fdf->pnts_amount);
	else if ((fdf->matrix[j][i] < fdf->matrix[j][i - 1])
	&& fdf->f_info[j][i] == NULL)
		fdf->img.addr[p_clr + 2] = fdf->crd[j][i - 1].clr->b - (fdf->grad
				* (fdf->matrix[j][i - 1] - fdf->matrix[j][i])
				* (double)fdf->pnts_amount);
	else
		fdf->img.addr[p_clr + 2] = fdf->crd[j][i].clr->b;
}
