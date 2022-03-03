/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:36:34 by gtaggana          #+#    #+#             */
/*   Updated: 2022/03/03 22:37:28 by ayglazko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_clean_coord(t_fdf *fdf, int j)
{
	while (++j < fdf->height)
		free(fdf->crd[j]);
	free(fdf->crd);
}

void	ft_clean_clr(t_fdf *fdf, int j, int i)
{
	while (++j < fdf->height)
	{
		i = 0;
		while (i < fdf->width)
		{
			free(fdf->crd[j][i].clr);
			i++;
		}
	}
}
