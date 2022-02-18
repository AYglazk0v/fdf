#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"

//utils_1.c

void	ft_errors(char *s);
size_t	ft_strlen(char *s);
char	*ft_strdup(const char *str);
void	ft_clear_finfo(t_fdf *fdf, int j, int i);
void	ft_clear_matrix(t_fdf *fdf, int i);

//utils_2.c

int		ft_isspace(int c);
int		ft_atoi(const char *str);
void	ft_free_map(char **map, int i);
int		ft_16to10(char *str, int p);
void	ft_bzero(void *s, size_t n);

//ft_split.c

size_t	ft_count_words(const char *str, char sep);
char	**ft_split(char const *s, char c);

#endif