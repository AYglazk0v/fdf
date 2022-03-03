/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:24:06 by gtaggana          #+#    #+#             */
/*   Updated: 2022/03/03 21:24:09 by ayglazko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_find_size(int fd, t_fdf *fdf)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_errors("Am I some kind of joke to you? The file is empty.\n");
	fdf->height = 1;
	fdf->width = ft_count_words(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fdf->height++;
		free(line);
	}
	close(fd);
}

static void	ft_alloc_matix(t_fdf *fdf, int j)
{
	fdf->f_info = (char ***)malloc(sizeof(char **) * fdf->height);
	if (!fdf->f_info)
		ft_errors("Malloc errors\n");
	fdf->matrix = (double **) malloc((sizeof(double *) * fdf->height));
	if (!fdf->matrix)
	{
		free(fdf->f_info);
		ft_errors("Malloc errors\n");
	}
	while (++j < fdf->height)
	{
		fdf->f_info[j] = (char **) malloc(sizeof (char *) * fdf->width);
		if (!fdf->f_info)
		{
			ft_clear_finfo(fdf, -1, 0);
			ft_errors("error malloc\n");
		}
		fdf->matrix[j] = (double *) malloc(sizeof(double) * fdf->width);
		if (!fdf->matrix[j])
		{
			ft_clear_finfo(fdf, -1, 0);
			ft_clear_matrix(fdf, -1);
			ft_errors("Error malloc\n");
		}
	}
}

static void	fill_matrix(t_fdf *fdf, int fd, char *line, int j)
{
	int		i;
	char	**map;
	char	*tmp;

	while (++j < fdf->height)
	{
		i = 0;
		line = get_next_line(fd);
		map = ft_split(line, ' ');
		while (map[i])
		{
			tmp = ft_strchr(map[i], ',');
			if (tmp)
				fdf->f_info[j][i] = ft_strdup(tmp + 3);
			else
				fdf->f_info[j][i] = tmp;
			fdf->matrix[j][i] = ft_atoi(map[i]);
			i++;
		}
		free(line);
		ft_free_map(map, -1);
	}
}

void	ft_read_map(t_fdf *fdf, int fd, char *map)
{
	char	*line;

	line = NULL;
	ft_find_size(fd, fdf);
	ft_alloc_matix(fdf, -1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_clear_finfo(fdf, -1, 0);
		ft_clear_matrix(fdf, -1);
		ft_errors("Card reading error, check the arguments.\n");
	}
	fill_matrix(fdf, fd, line, -1);
}
