#include "../../includes/utils.h"

int	ft_isspace(int c)
{
	if ((c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long unsigned int	num;
	int					sign;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		if ((num >= __LONG_MAX__) && sign > 0)
			return (-1);
		if ((num > __LONG_MAX__) && sign < 0)
			return (0);
	}
	return (sign * (int)num);
}

int		ft_16to10(char *str, int p)
{
	int		i;
	int		res;
	int		tmp;

	res = 0;
	i = 1;
	while (i >= 0)
	{
		if (str[p] >= 'A' && str[p] <= 'F')
			tmp = str[p] - 55;
		else
			tmp = str[p] - 48;
		res = res + tmp * pow(16, i);
		i--;
	}
	return (res);
}

void	ft_free_map(char **map, int i)
{
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		arr[i] = '\0';
		i++;
	}
}