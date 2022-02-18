#include "../includes/fdf.h"

static void	ft_motion_but_1(t_fdf *fdf, int x, int y)
{
	if (abs(y - fdf->pre_y) > 5)
		fdf->alfa += (y - fdf->pre_y) * -0.005;
	if (abs(x - fdf->pre_x) > 5)
		fdf->gamma += (x - fdf->pre_x) * -0.005;
	if (abs(y - fdf->pre_y) > 5 || abs(x - fdf->pre_x) > 5)
	{
		fdf->pre_x = x;
		fdf->pre_y = y;
		ft_rotate(fdf, -1, 0);
		ft_draw(fdf, -1, 0);
	}
}

int		ft_mouse_press(int key, int x, int y, t_fdf *fdf)
{
	if (x <= 0 || x >= fdf->hei || y <= 0 || y >= fdf->wid)
		return (0);
	if (key == 1)
		fdf->press_1 = 1;
	if (key == 2)
		fdf->press_2 = 1;
	if (key == 4)
	{
		fdf->zoom += 2;
		ft_draw(fdf, -1, 0);
	}
	if (key == 5)
	{
		if (fdf->zoom > 2)
			fdf->zoom -= 2;
		ft_draw(fdf, -1, 0);
	}
	return (0);
}

int		ft_mouse_release(int key, int x, int y, t_fdf *fdf)
{
	if (x <= 0 || x >= fdf->hei || y <= 0 || y >= fdf->wid)
		return (0);
	if (key == 1)
		fdf->press_1 = 0;
	if (key == 2)
		fdf->press_2 = 0;
	return (0);
}

int		ft_mouse_motion(int x, int y, t_fdf *fdf)
{
	if (abs(y - fdf->pre_y) > 25 || abs(x - fdf->pre_x) > 25)
	{
		fdf->pre_x = x;
		fdf->pre_y = y;
	}
	if (fdf->press_1 == 1)
		motion_but_1(fdf, x, y);
	if (fdf->press_2 == 1)
	{
		fdf->def_y += (y - fdf->pre_y) * 0.8;
		fdf->def_x += (x - fdf->pre_x) * 0.8;
		fdf->pre_x = x;
		fdf->pre_y = y;
		ft_draw(fdf, -1, 0);
	}
	return (0);
}
