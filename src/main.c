/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:23:58 by gtaggana          #+#    #+#             */
/*   Updated: 2022/03/03 22:34:17 by ayglazko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_wasdqe(t_fdf *fdf, int key)
{
	if (key == B_A)
		fdf->betta += 0.07;
	else if (key == B_D)
		fdf->betta -= 0.07;
	else if (key == B_S)
		fdf->alfa -= 0.07;
	else if (key == B_W)
		fdf->alfa += 0.07;
	else if (key == B_Q)
		fdf->gamma += 0.07;
	else if (key == B_E)
		fdf->gamma -= 0.07;
	else if (key == B_AR_U)
		fdf->def_y -= 10;
	else if (key == B_AR_D)
		fdf->def_y += 10;
	else if (key == B_AR_L)
		fdf->def_x -= 10;
	else if (key == B_AR_R)
		fdf->def_x += 10;
	else if (key == B_P)
		fdf->projection = 'P';
	else if (key == B_I)
		fdf->projection = 'I';
}

void	ft_zx(t_fdf *fdf, int key, int j, int i)
{
	if (key == B_Z)
	{
		while (++j < fdf->height)
		{
			i = -1;
			while (++i < fdf->width)
				fdf->matrix[j][i] /= 1.1;
		}
		fdf->maxh /= 1.1;
		fdf->minh /= 1.1;
	}
	else if (key == B_X)
	{
		while (++j < fdf->height)
		{
			i = -1;
			while (++i < fdf->width)
				fdf->matrix[j][i] *= 1.1;
		}
		fdf->maxh *= 1.1;
		fdf->minh *= 1.1;
	}
}

int	ft_key_press(int key, t_fdf *fdf)
{
	if (key == B_ESC)
		exit(0);
	ft_wasdqe(fdf, key);
	ft_zx(fdf, key, -1, 0);
	if (key == B_PLUS)
		fdf->zoom += 2;
	else if (key == B_MINUS)
	{
		if (fdf->zoom > 2)
			fdf->zoom -= 2;
	}
	else if (key == B_SPACE)
		fdf->clr.r = (fdf->clr.r + 20) % 255;
	else if (key == B_TAB)
		fdf->clr.b = (fdf->clr.b + 20) % 255;
	ft_pix_map(fdf, -1, 0);
	ft_rotate(fdf, -1, 0);
	ft_draw(fdf, 0, 0);
	return (0);
}

static void	ft_end_prog(int argc, t_fdf *fdf)
{
	if (argc == 2)
	{
		ft_clear_finfo(fdf, -1, -1);
		ft_clear_matrix(fdf, -1);
		ft_clean_clr(fdf, -1, -1);
		ft_clean_coord(fdf, -1);
	}
	else
		ft_errors("invalid cnt argv\n");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_errors("Card reading error, check the arguments.\n");
		ft_read_map(&fdf, fd, argv[1]);
		ft_init_fdf(&fdf);
		ft_pix_map(&fdf, -1, 0);
		ft_draw(&fdf, 0, 0);
		mlx_hook(fdf.win_ptr, 2, (1L << 0), ft_key_press, &fdf);
		mlx_hook(fdf.win_ptr, 4, (1L << 2), ft_mouse_press, &fdf);
		mlx_hook(fdf.win_ptr, 5, (1L << 3), ft_mouse_release, &fdf);
		mlx_hook(fdf.win_ptr, 6, (1L << 6), ft_mouse_motion, &fdf);
		mlx_loop(fdf.mlx_ptr);
		close(fd);
	}
	ft_end_prog(argc, &fdf);
	return (0);
}
