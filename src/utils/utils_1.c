#include "../../includes/utils.h"

void	ft_errors(char *s)
{
	write (2, s, ft_strlen(s));
	exit (1);
}

size_t ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i;
	int		size;

	i = 0;
	size = 0;
	size = ft_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (cpy == NULL)
		return ((void *)0);
	while (size--)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_clear_finfo(t_fdf *fdf, int j, int i)
{
	while(++j < fdf->height)
	{
		i = 0;
		while(i++ < fdf->width)
		{
			free(fdf->f_info[j][i]);
			fdf->f_info[j][i] = NULL;
		}
		free(fdf->f_info[j]);
		fdf->f_info[j] = NULL;
	}
	free(fdf->f_info);
	fdf->f_info = NULL;
}

void	ft_clear_matrix(t_fdf *fdf, int i)
{
	while (++i < fdf->height)
		free(fdf->matrix[i]);
	free(fdf->matrix);
}

